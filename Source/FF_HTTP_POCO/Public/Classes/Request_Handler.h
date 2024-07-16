#pragma once

#include "FF_HTTP_POCO_Includes.h"
#include "FF_HTTP_POCO_Server.h"

class ReqHandler : public HTTPRequestHandler
{

private:

	virtual bool IsApiRequest(FString InReqUri);

public:

	AHTTP_Server_POCO* Owner = nullptr;

	virtual void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);

};