#include "Classes/Request_Handler_Factory.h"

ReqHandler* ReqHandlerFactory::createRequestHandler(const HTTPServerRequest& ServerRequests)
{
	ReqHandler* RequestHandler = new ReqHandler;
	RequestHandler->Owner = this->Owner;

	return RequestHandler;
}