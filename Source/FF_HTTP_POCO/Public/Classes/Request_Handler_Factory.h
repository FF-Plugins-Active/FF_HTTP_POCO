#pragma once

#include "Classes/Request_Handler.h"

class ReqHandlerFactory : public HTTPRequestHandlerFactory
{
public:

	AHTTP_Server_POCO* Owner = nullptr;
	virtual ReqHandler* createRequestHandler(const HTTPServerRequest&);
};