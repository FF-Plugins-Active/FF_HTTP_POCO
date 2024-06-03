// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_POCO_Thread.h"
#include "FF_HTTP_POCO_Server.h"

// UE Includes.
#include "Async/Async.h"

bool ReqHandler::IsApiRequest(FString InReqUri)
{
	TArray<FString> Sections_URI_Api = UKismetStringLibrary::ParseIntoArray(this->Owner->API_URI, "/");
	TArray<FString> Sections_URI_Req = UKismetStringLibrary::ParseIntoArray(InReqUri, "/");

	if (Sections_URI_Api.Num() > Sections_URI_Req.Num())
	{
		return false;
	}

	for (int32 Index_Section = 0; Index_Section < Sections_URI_Api.Num(); Index_Section++)
	{
		if (Sections_URI_Req[Index_Section] != Sections_URI_Api[Index_Section])
		{
			return false;
		}
	}

	return true;
}

#if (ENABLE_SERVE_STATIC_PAGE == 1)
void ReqHandler::ServeStaticPage(FString InReqUri, HTTPServerResponse& response)
{
	FString RequestedPage;
	FString TempRoot = this->Owner->Server_Path_Root;
	FPaths::NormalizeFilename(TempRoot);

	if (InReqUri == "/" || InReqUri == this->Owner->Server_Path_Index)
	{
		RequestedPage = TempRoot + this->Owner->Server_Path_Index;

		FPaths::MakePlatformFilename(RequestedPage);
		response.sendFile(TCHAR_TO_UTF8(*RequestedPage), "text/html");

		return;
	}

	else
	{
		RequestedPage = TempRoot + InReqUri;

		if (FPaths::FileExists(RequestedPage))
		{
			FPaths::MakePlatformFilename(RequestedPage);
			response.sendFile(TCHAR_TO_UTF8(*RequestedPage), "text/html");

			return;
		}

		else
		{
			RequestedPage = TempRoot + this->Owner->Server_Path_404;

			FPaths::MakePlatformFilename(RequestedPage);
			response.sendFile(TCHAR_TO_UTF8(*RequestedPage), "text/html");

			return;
		}
	}
}
#endif

void ReqHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	if (!this->Owner)
	{
		return;
	}

	FString RequestUri = request.getURI().c_str();

	if (this->IsApiRequest(RequestUri))
	{
		UHttpRequestPoco* RequestObject = NewObject<UHttpRequestPoco>();
		RequestObject->HTTP_Request = &request;
		RequestObject->HTTP_Response = &response;
		RequestObject->RequestUri = RequestUri;

		this->Owner->Parent_Actor->DelegateHttpRequest.Broadcast(RequestObject);

		return;
	}

	else
	{
		response.setChunkedTransferEncoding(true);
		response.setContentType("text/html");

		response.send()
			<< "<html>"
			<< "<head><title>UE5 POCO C++ Server</title></head>"
			<< "<body><h1>Please use correct API URL</h1></body>"
			<< "</html>";
	}
}

ReqHandler* ReqHandlerFactory::createRequestHandler(const HTTPServerRequest&)
{
	ReqHandler* RequestHandler = new ReqHandler;
	RequestHandler->Owner = this->Owner;
	
	return RequestHandler;
}

FHTTP_Thread_POCO::FHTTP_Thread_POCO(AHTTP_Server_POCO* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Port_HTTP = this->Parent_Actor->Port_HTTP;
	this->Port_HTTPS = this->Parent_Actor->Port_HTTPS;
	this->ThreadNum = this->Parent_Actor->ThreadNum;
	
	this->API_URI = this->Parent_Actor->API_URI;

#if (ENABLE_SERVE_STATIC_PAGE == 1)
	this->Server_Path_Root = this->Parent_Actor->Server_Path_Root;
	this->Server_Path_Index = this->Parent_Actor->Server_Path_Index;
	this->Server_Path_404 = this->Parent_Actor->Server_Path_404;
#endif

	this->RunnableThread = FRunnableThread::Create(this, *this->Parent_Actor->Server_Name);
}

FHTTP_Thread_POCO::~FHTTP_Thread_POCO()
{
	if (this->RunnableThread)
	{
		this->RunnableThread->Kill(true);
		delete this->RunnableThread;
	}
}

bool FHTTP_Thread_POCO::Init()
{	
	this->Callback_HTTP_Start();
	this->bStartThread = true;

	return true;
}

uint32 FHTTP_Thread_POCO::Run()
{
	while (this->bStartThread)
	{
		//FDateTime Now;
		//UE_LOG(LogTemp, Display, TEXT("Workflow server is running : %s"), *Now.ToString());
	}

	return 0;
}

void FHTTP_Thread_POCO::Stop()
{
	this->Callback_HTTP_Stop();
	
	this->bStartThread = false;
}

bool FHTTP_Thread_POCO::Toggle(bool bIsPause)
{
	if (!this->RunnableThread)
	{
		return false;
	}

	this->RunnableThread->Suspend(bIsPause);
	
	return true;
}

void FHTTP_Thread_POCO::Callback_HTTP_Start()
{	
	HTTPServerParams* POCO_Server_Params = new HTTPServerParams;
	POCO_Server_Params->setMaxThreads(this->ThreadNum);
	
	ServerSocket PocoServerSocket(this->Port_HTTP);
	
	ReqHandlerFactory* HandlerFactory = new ReqHandlerFactory;
	HandlerFactory->Owner = this;

	this->POCO_Server = MakeShared<HTTPServer>(HandlerFactory, PocoServerSocket, POCO_Server_Params);
	this->POCO_Server->start();
}

void FHTTP_Thread_POCO::Callback_HTTP_Stop()
{
	if (this->POCO_Server.IsValid())
	{
		this->POCO_Server->stopAll(true);
	}
}