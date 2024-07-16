#pragma once

#include "Kismet/KismetStringLibrary.h"

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
#include "Poco/SharedPtr.h"
#include "Poco/Exception.h"

#include "Windows/HideWindowsPlatformTypes.h"

#endif
THIRD_PARTY_INCLUDES_END
