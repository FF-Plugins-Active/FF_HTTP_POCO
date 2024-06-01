#pragma once

#include "CoreMinimal.h"

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
#include "Poco/Util/ServerApplication.h"

#include "Windows/HideWindowsPlatformTypes.h"

#endif
THIRD_PARTY_INCLUDES_END

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;

#include "FF_HTTP_POCO_Request.generated.h"

UCLASS(BlueprintType)
class FF_HTTP_POCO_API UHttpRequestPoco : public UObject
{
	GENERATED_BODY()

public:

	HTTPServerRequest* HTTP_Request = nullptr;
	HTTPServerResponse* HTTP_Response = nullptr;

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse(FString In_Response = "<html>Hello World!</html>");

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestUri(FString& Out_Uri);

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestQuery(TMap<FString, FString>& Out_Query, FString& Query_Title);
	
	UFUNCTION(BlueprintCallable)
	virtual bool GetHeaders(TMap<FString, FString>& Out_Headers);

	UFUNCTION(BlueprintCallable)
	virtual bool GetBody(FString& Out_Body);

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRequestPoco, UHttpRequestPoco*, Request);