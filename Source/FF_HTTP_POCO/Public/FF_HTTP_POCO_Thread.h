// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

#include "FF_HTTP_POCO_Includes.h"

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;
using namespace Poco::Data::ODBC;

// Fordward Declerations.
class FRunnableThread;
class AHTTP_Server_POCO;

class FHTTP_Thread_POCO : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_POCO(AHTTP_Server_POCO* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_POCO() override;

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual bool Toggle(bool bIsPause);

	AHTTP_Server_POCO* Parent_Actor = nullptr;
	
	FString API_URI = "";

private:

	virtual void Callback_HTTP_Start();
	virtual void Callback_HTTP_Stop();

	FRunnableThread* RunnableThread = nullptr;
	bool bStartThread = false;

	int32 Port_HTTP = 8081;
	int32 Port_HTTPS = 8443;
	int32 ThreadNum = 4;

	Poco::SharedPtr<HTTPServer> POCO_Server;

};

class ReqHandler : public HTTPRequestHandler
{

private:

	virtual bool IsApiRequest(FString InReqUri);

public:

	FHTTP_Thread_POCO* Owner = nullptr;
	
	virtual void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);

};

class ReqHandlerFactory : public HTTPRequestHandlerFactory
{
public:

	FHTTP_Thread_POCO* Owner = nullptr;
	virtual ReqHandler* createRequestHandler(const HTTPServerRequest&);
};