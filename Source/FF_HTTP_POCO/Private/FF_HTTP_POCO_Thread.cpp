// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_POCO_Thread.h"
#include "FF_HTTP_POCO_Server.h"

// UE Includes.
#include "Async/Async.h"

void ReqHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	UHttpRequestPoco* RequestObject = NewObject<UHttpRequestPoco>();
	RequestObject->HTTP_Request = &request;
	RequestObject->HTTP_Response = &response;
	
	this->Owner->Parent_Actor->DelegateHttpRequest.Broadcast(RequestObject);
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
	POCO_Server_Params->setMaxThreads(4);
	
	ServerSocket Socket(this->Port_HTTP);

	ReqHandlerFactory* HandlerFactory = new ReqHandlerFactory;
	HandlerFactory->Owner = this;
	
	this->POCO_Server = MakeShared<HTTPServer>(HandlerFactory, Socket, POCO_Server_Params);
	this->POCO_Server->start();
}

void FHTTP_Thread_POCO::Callback_HTTP_Stop()
{
	if (this->POCO_Server.IsValid())
	{
		this->POCO_Server->stopAll(true);
	}
}