// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_POCO_Thread.h"
#include "FF_HTTP_POCO_Server.h"

// UE Includes.
#include "Async/Async.h"

void HelloRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	//Application& app = Application::instance();
	//app.logger().information("Request from %s"s, request.clientAddress().toString());

	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html"s);

	response.send()
		<< "<html>"
		<< "<head><title>Hello</title></head>"
		<< "<body><h1>Hello from the POCO Web Server</h1></body>"
		<< "</html>";
}

HTTPRequestHandler* HelloRequestHandlerFactory::createRequestHandler(const HTTPServerRequest&)
{
	return new HelloRequestHandler;
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

	this->POCO_Server = MakeShared<HTTPServer>(new HelloRequestHandlerFactory, Socket, POCO_Server_Params);
	this->POCO_Server->start();
}

void FHTTP_Thread_POCO::Callback_HTTP_Stop()
{
	if (this->POCO_Server.IsValid())
	{
		this->POCO_Server->stopAll(true);
	}
}