#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "Kismet/KismetStringLibrary.h"

// Custom Includes.
#include "FF_HTTP_POCO_Enums.h"

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

private:

	virtual HTTPResponse::HTTPStatus ConvertToPocoStatus(EPocoStatusCodes In_Status);
	virtual std::string ConvertToPocoMime(EPocoContentTypes In_ContenTypes);

public:

	HTTPServerRequest* HTTP_Request = nullptr;
	HTTPServerResponse* HTTP_Response = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	FString RequestUri;

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse_String(TMap<FString, FString> In_Headers, FString In_Response, EPocoStatusCodes In_Status = EPocoStatusCodes::OK_200, EPocoContentTypes In_ContentTypes = EPocoContentTypes::Text_Plain, bool bChunkedTransferEncoding = true);

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestQuery(TMap<FString, FString>& Out_Query, FString& Query_Title);
	
	UFUNCTION(BlueprintCallable)
	virtual bool GetHeaders(TMap<FString, FString>& Out_Headers);

	UFUNCTION(BlueprintCallable)
	virtual bool GetBody(FString& Out_Body);

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRequestPoco, UHttpRequestPoco*, Request);