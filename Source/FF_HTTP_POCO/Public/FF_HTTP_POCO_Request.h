#pragma once

#include "CoreMinimal.h"

// Custom Includes.
#include "FF_HTTP_POCO_Enums.h"
#include "FF_HTTP_POCO_Includes.h"

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;
using namespace Poco::Data::ODBC;

#include "FF_HTTP_POCO_Request.generated.h"

UCLASS(BlueprintType)
class FF_HTTP_POCO_API UHttpRequestPoco : public UObject
{
	GENERATED_BODY()

private:

	HTTPServerRequest* HTTP_Request = nullptr;
	HTTPServerResponse* HTTP_Response = nullptr;
	FString RequestUri;

	virtual HTTPResponse::HTTPStatus ConvertToPocoStatus(EPocoStatusCodes In_Status);
	virtual std::string ConvertToPocoMime(EPocoContentTypes In_ContenTypes);

public:
	
	virtual bool SetRequest(HTTPServerRequest* In_Request);
	virtual bool GetRequest(HTTPServerRequest*& Out_Request);
	virtual bool SetResponse(HTTPServerResponse* In_Response);
	virtual bool GetResponse(HTTPServerResponse*& Out_Response);
	virtual void SetRequestUri(const FString& In_Uri);

	UFUNCTION(BlueprintPure)
	virtual FString GetRequestUri();

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse_String(TMap<FString, FString> In_Headers, FString In_Response, EPocoStatusCodes In_Status = EPocoStatusCodes::OK_200, EPocoContentTypes In_ContentTypes = EPocoContentTypes::Text_Plain, bool bChunkedTransferEncoding = true);

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse_Buffer(TMap<FString, FString> In_Headers, TArray<uint8> In_Response, EPocoStatusCodes In_Status = EPocoStatusCodes::OK_200, EPocoContentTypes In_ContentTypes = EPocoContentTypes::Text_Plain, bool bChunkedTransferEncoding = true);

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestQuery(TMap<FString, FString>& Out_Query, FString& Query_Title);
	
	UFUNCTION(BlueprintCallable)
	virtual bool GetAllHeaders(TMap<FString, FString>& Out_Headers);

	UFUNCTION(BlueprintCallable)
	virtual bool GetHeader(FString& Value, FString Key);

	UFUNCTION(BlueprintCallable)
	virtual bool GetMethod(FString& Out_Method);

	UFUNCTION(BlueprintCallable)
	virtual bool GetContentLenght64(int64& Out_Lenght);

	UFUNCTION(BlueprintCallable)
	virtual bool GetVersion(FString& Out_Version);

	UFUNCTION(BlueprintCallable)
	virtual bool GetClientAddress(FString& Out_Address);

	UFUNCTION(BlueprintCallable)
	virtual bool GetHostName(FString& Out_Host);

	UFUNCTION(BlueprintCallable)
	virtual bool GetBody(FString& Out_Body);

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRequestPoco, UHttpRequestPoco*, Request);