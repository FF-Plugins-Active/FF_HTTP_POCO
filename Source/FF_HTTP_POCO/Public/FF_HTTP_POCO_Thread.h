// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START

#ifdef _WIN64
#define WIN32_LEAN_AND_MEAN
#include "Windows/AllowWindowsPlatformTypes.h"

#include "winsvc.h"

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/SocketAddressImpl.h"

#include "Poco/Util/ServerApplication.h"

#include "Poco/Data/ODBC/Connector.h"

#include "Windows/HideWindowsPlatformTypes.h"

#endif
THIRD_PARTY_INCLUDES_END

#define ENABLE_SERVE_STATIC_PAGE 0

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

#if (ENABLE_SERVE_STATIC_PAGE == 1)
	FString Server_Path_Root = "";
	FString Server_Path_Index = "/index.html";
	FString Server_Path_404 = "/404.html";
#endif
	
	FString API_URI = "";

private:

	virtual void Callback_HTTP_Start();
	virtual void Callback_HTTP_Stop();

	FRunnableThread* RunnableThread = nullptr;
	bool bStartThread = false;

	int32 Port_HTTP = 8081;
	int32 Port_HTTPS = 8443;
	int32 ThreadNum = 4;

	TSharedPtr<HTTPServer> POCO_Server;

};

class ReqHandler : public HTTPRequestHandler
{

private:

	virtual bool IsApiRequest(FString InReqUri);

#if (ENABLE_SERVE_STATIC_PAGE == 1)
	virtual void ServeStaticPage(FString InReqUri, HTTPServerResponse& response);
#endif

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