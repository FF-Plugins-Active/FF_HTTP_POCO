#include "FF_HTTP_POCO_Request.h"

HTTPResponse::HTTPStatus UHttpRequestPoco::ConvertToPocoStatus(EPocoStatusCodes In_Status)
{
	switch (In_Status)
	{
	case EPocoStatusCodes::Continue_100:
		return HTTPResponse::HTTPStatus::HTTP_CONTINUE;
	
	case EPocoStatusCodes::Switching_Protocols_101:
		return HTTPResponse::HTTPStatus::HTTP_SWITCHING_PROTOCOLS;
	
	case EPocoStatusCodes::Processing_102:
		return HTTPResponse::HTTPStatus::HTTP_PROCESSING;
	
	case EPocoStatusCodes::OK_200:
		return HTTPResponse::HTTPStatus::HTTP_OK;
	
	case EPocoStatusCodes::Created_201:
		return HTTPResponse::HTTPStatus::HTTP_CREATED;
	
	case EPocoStatusCodes::Accepted_202:
		return HTTPResponse::HTTPStatus::HTTP_ACCEPTED;
	
	case EPocoStatusCodes::Non_Authoratative_Information_203:
		return HTTPResponse::HTTPStatus::HTTP_NONAUTHORITATIVE;
	
	case EPocoStatusCodes::No_Content_204:
		return HTTPResponse::HTTPStatus::HTTP_NO_CONTENT;
	
	case EPocoStatusCodes::Reset_Content_205:
		return HTTPResponse::HTTPStatus::HTTP_RESET_CONTENT;
	
	case EPocoStatusCodes::Partial_Content_206:
		return HTTPResponse::HTTPStatus::HTTP_PARTIAL_CONTENT;
	
	case EPocoStatusCodes::Multi_Status_207:
		return HTTPResponse::HTTPStatus::HTTP_MULTI_STATUS;
	
	case EPocoStatusCodes::Already_Reported_208:
		return HTTPResponse::HTTPStatus::HTTP_ALREADY_REPORTED;
	
	case EPocoStatusCodes::Im_Used_226:
		return HTTPResponse::HTTPStatus::HTTP_IM_USED;
	
	case EPocoStatusCodes::Multiple_Choice_300:
		return HTTPResponse::HTTPStatus::HTTP_MULTIPLE_CHOICES;
	
	case EPocoStatusCodes::Moved_Permanently_301:
		return HTTPResponse::HTTPStatus::HTTP_MOVED_PERMANENTLY;
	
	case EPocoStatusCodes::Found_302:
		return HTTPResponse::HTTPStatus::HTTP_FOUND;
	
	case EPocoStatusCodes::See_Other_303:
		return HTTPResponse::HTTPStatus::HTTP_SEE_OTHER;
	
	case EPocoStatusCodes::Not_Modified_304:
		return HTTPResponse::HTTPStatus::HTTP_NOT_MODIFIED;
	
	case EPocoStatusCodes::Use_Proxy_305:
		return HTTPResponse::HTTPStatus::HTTP_USEPROXY;
	
	case EPocoStatusCodes::Temporary_Redirect_307:
		return HTTPResponse::HTTPStatus::HTTP_TEMPORARY_REDIRECT;
	
	case EPocoStatusCodes::Permanent_Redirect_308:
		return HTTPResponse::HTTPStatus::HTTP_PERMANENT_REDIRECT;
	
	case EPocoStatusCodes::Bad_Request_400:
		return HTTPResponse::HTTPStatus::HTTP_BAD_REQUEST;
	
	case EPocoStatusCodes::Unauthorized_401:
		return HTTPResponse::HTTPStatus::HTTP_UNAUTHORIZED;
	
	case EPocoStatusCodes::Payment_Required_402:
		return HTTPResponse::HTTPStatus::HTTP_PAYMENT_REQUIRED;
	
	case EPocoStatusCodes::Forbidden_403:
		return HTTPResponse::HTTPStatus::HTTP_FORBIDDEN;
	
	case EPocoStatusCodes::Not_Found_404:
		return HTTPResponse::HTTPStatus::HTTP_NOT_FOUND;
	
	case EPocoStatusCodes::Method_Not_Allowed_405:
		return HTTPResponse::HTTPStatus::HTTP_METHOD_NOT_ALLOWED;
	
	case EPocoStatusCodes::Not_Acceptable_406:
		return HTTPResponse::HTTPStatus::HTTP_NOT_ACCEPTABLE;
	
	case EPocoStatusCodes::Proxy_Authentication_Required_407:
		return HTTPResponse::HTTPStatus::HTTP_PROXY_AUTHENTICATION_REQUIRED;
	
	case EPocoStatusCodes::Request_Timeout_408:
		return HTTPResponse::HTTPStatus::HTTP_REQUEST_TIMEOUT;
	
	case EPocoStatusCodes::Conflict_409:
		return HTTPResponse::HTTPStatus::HTTP_CONFLICT;
	
	case EPocoStatusCodes::Gone_410:
		return HTTPResponse::HTTPStatus::HTTP_GONE;
	
	case EPocoStatusCodes::Lenght_Required_411:
		return HTTPResponse::HTTPStatus::HTTP_LENGTH_REQUIRED;
	
	case EPocoStatusCodes::Precondition_Failed_412:
		return HTTPResponse::HTTPStatus::HTTP_PRECONDITION_FAILED;
	
	case EPocoStatusCodes::Payload_Too_Large_413:
		return HTTPResponse::HTTPStatus::HTTP_REQUEST_ENTITY_TOO_LARGE;
	
	case EPocoStatusCodes::Uri_Too_Long_414:
		return HTTPResponse::HTTPStatus::HTTP_REQUEST_URI_TOO_LONG;
	
	case EPocoStatusCodes::Unsupported_Media_Type_415:
		return HTTPResponse::HTTPStatus::HTTP_UNSUPPORTED_MEDIA_TYPE;
	
	case EPocoStatusCodes::Range_Not_Satisfiable_416:
		return HTTPResponse::HTTPStatus::HTTP_REQUESTED_RANGE_NOT_SATISFIABLE;
	
	case EPocoStatusCodes::Expectation_Failed_417:
		return HTTPResponse::HTTPStatus::HTTP_EXPECTATION_FAILED;
	
	case EPocoStatusCodes::Misdirected_Request_421:
		return HTTPResponse::HTTPStatus::HTTP_MISDIRECTED_REQUEST;
	
	case EPocoStatusCodes::Unprocessable_Entity_422:
		return HTTPResponse::HTTPStatus::HTTP_UNPROCESSABLE_ENTITY;
	
	case EPocoStatusCodes::Locked_423:
		return HTTPResponse::HTTPStatus::HTTP_LOCKED;
	case EPocoStatusCodes::Failed_Dependency_424:
		return HTTPResponse::HTTPStatus::HTTP_FAILED_DEPENDENCY;
	
	case EPocoStatusCodes::Upgrade_Required_426:
		return HTTPResponse::HTTPStatus::HTTP_UPGRADE_REQUIRED;
	
	case EPocoStatusCodes::Precondition_Required_428:
		return HTTPResponse::HTTPStatus::HTTP_PRECONDITION_REQUIRED;
	
	case EPocoStatusCodes::Too_Many_Requests_429:
		return HTTPResponse::HTTPStatus::HTTP_TOO_MANY_REQUESTS;
	
	case EPocoStatusCodes::Request_Header_Fields_Too_Large_431:
		return HTTPResponse::HTTPStatus::HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE;
	
	case EPocoStatusCodes::Unavailable_For_Legal_Reasons_451:
		return HTTPResponse::HTTPStatus::HTTP_UNAVAILABLE_FOR_LEGAL_REASONS;
	
	case EPocoStatusCodes::Internal_Server_Error_500:
		return HTTPResponse::HTTPStatus::HTTP_INTERNAL_SERVER_ERROR;
	
	case EPocoStatusCodes::Not_Implemented_501:
		return HTTPResponse::HTTPStatus::HTTP_NOT_IMPLEMENTED;
	
	case EPocoStatusCodes::Bad_Gateway_502:
		return HTTPResponse::HTTPStatus::HTTP_BAD_GATEWAY;
	
	case EPocoStatusCodes::Service_Unavailable_503:
		return HTTPResponse::HTTPStatus::HTTP_SERVICE_UNAVAILABLE;
	
	case EPocoStatusCodes::Gateway_Timeout_504:
		return HTTPResponse::HTTPStatus::HTTP_GATEWAY_TIMEOUT;
	
	case EPocoStatusCodes::Http_Version_Not_Supported_505:
		return HTTPResponse::HTTPStatus::HTTP_VERSION_NOT_SUPPORTED;
	
	case EPocoStatusCodes::Variant_Also_Negotiates_506:
		return HTTPResponse::HTTPStatus::HTTP_VARIANT_ALSO_NEGOTIATES;
	
	case EPocoStatusCodes::Insufficient_Storage_507:
		return HTTPResponse::HTTPStatus::HTTP_INSUFFICIENT_STORAGE;
	
	case EPocoStatusCodes::Loop_Detected_508:
		return HTTPResponse::HTTPStatus::HTTP_LOOP_DETECTED;
	
	case EPocoStatusCodes::Not_Extended_510:
		return HTTPResponse::HTTPStatus::HTTP_NOT_EXTENDED;
	
	case EPocoStatusCodes::Network_Authentication_Required_511:
		return HTTPResponse::HTTPStatus::HTTP_NETWORK_AUTHENTICATION_REQUIRED;
	
	default:
		return HTTPResponse::HTTPStatus::HTTP_NOT_FOUND;
	}
}

std::string UHttpRequestPoco::ConvertToPocoMime(EPocoContentTypes In_ContenTypes)
{
	switch (In_ContenTypes)
	{
	case EPocoContentTypes::Application_7z:
		return "";
	
	case EPocoContentTypes::Application_Atom:
		return "";
	
	case EPocoContentTypes::Application_Docx:
		return "";
	
	case EPocoContentTypes::Application_Eot:
		return "";
	
	case EPocoContentTypes::Application_Excel:
		return "";
	
	case EPocoContentTypes::Application_gRPC:
		return "";
	
	case EPocoContentTypes::Application_gzip:
		return "";
	
	case EPocoContentTypes::Application_JAR:
		return "";
	
	case EPocoContentTypes::Application_JS:
		return "";
	
	case EPocoContentTypes::Application_Json:
		return "";
	
	case EPocoContentTypes::Application_M3U8:
		return "";
	
	case EPocoContentTypes::Application_Octet_Stream:
		return "";
	
	case EPocoContentTypes::Application_PDF:
		return "";
	
	case EPocoContentTypes::Application_PPT:
		return "";
	
	case EPocoContentTypes::Application_PPTX:
		return "";
	
	case EPocoContentTypes::Application_RAR:
		return "";
	
	case EPocoContentTypes::Application_RSS:
		return "";
	
	case EPocoContentTypes::Application_RTF:
		return "";
	
	case EPocoContentTypes::Application_URLENCODED:
		return "";
	
	case EPocoContentTypes::Application_WASM:
		return "";
	
	case EPocoContentTypes::Application_WORD:
		return "";
	
	case EPocoContentTypes::Application_XHTML:
		return "";
	
	case EPocoContentTypes::Application_XLSX:
		return "";
	
	case EPocoContentTypes::Application_XML:
		return "";
	
	case EPocoContentTypes::Application_ZIP:
		return "";
	
	case EPocoContentTypes::Audio_AAC:
		return "";
	
	case EPocoContentTypes::Audio_M4A:
		return "";
	
	case EPocoContentTypes::Audio_MP3:
		return "";
	
	case EPocoContentTypes::Audio_OGG:
		return "";
	
	case EPocoContentTypes::Audio_OPUS:
		return "";
	
	case EPocoContentTypes::Audio_PCMA:
		return "";
	
	case EPocoContentTypes::Content_Type_Application:
		return "";
	
	case EPocoContentTypes::Content_Type_Audio:
		return "";
	
	case EPocoContentTypes::Content_Type_Font:
		return "";
	
	case EPocoContentTypes::Content_Type_Image:
		return "";
	
	case EPocoContentTypes::Content_Type_Multipart:
		return "";
	
	case EPocoContentTypes::Content_Type_NONE:
		return "";
	
	case EPocoContentTypes::Content_Type_Text:
		return "";
	
	case EPocoContentTypes::Content_Type_Undefined:
		return "";
	
	case EPocoContentTypes::Content_Type_Video:
		return "";
	
	case EPocoContentTypes::Font_OTF:
		return "";
	
	case EPocoContentTypes::Font_TTF:
		return "";
	
	case EPocoContentTypes::Font_WOFF:
		return "";
	
	case EPocoContentTypes::Font_WOFF2:
		return "";
	
	case EPocoContentTypes::Image_BMP:
		return "";
	
	case EPocoContentTypes::Image_GIF:
		return "";
	
	case EPocoContentTypes::Image_ICO:
		return "";
	
	case EPocoContentTypes::Image_JPG:
		return "";
	
	case EPocoContentTypes::Image_PNG:
		return "";
	
	case EPocoContentTypes::Image_SVG:
		return "";
	
	case EPocoContentTypes::Image_TIFF:
		return "";
	
	case EPocoContentTypes::Image_WEBP:
		return "";
	
	case EPocoContentTypes::Multiplart_Form_Data:
		return "";
	
	case EPocoContentTypes::Text_CSS:
		return "";
	
	case EPocoContentTypes::Text_CSV:
		return "";
	
	case EPocoContentTypes::Text_Event_Stream:
		return "";
	
	case EPocoContentTypes::Text_HTML:
		return "text/html";
	
	case EPocoContentTypes::Text_Markdown:
		return "";
	
	case EPocoContentTypes::Text_Plain:
		return "text/plain";
	
	case EPocoContentTypes::Video_3GPP:
		return "";
	
	case EPocoContentTypes::Video_ASF:
		return "";
	
	case EPocoContentTypes::Video_AVI:
		return "";
	
	case EPocoContentTypes::Video_FLV:
		return "";
	
	case EPocoContentTypes::Video_M4V:
		return "";
	
	case EPocoContentTypes::Video_MNG:
		return "";
	
	case EPocoContentTypes::Video_MOV:
		return "";
	
	case EPocoContentTypes::Video_MP4:
		return "";
	
	case EPocoContentTypes::Video_MPEG:
		return "";
	
	case EPocoContentTypes::Video_TS:
		return "";
	
	case EPocoContentTypes::Video_WEBM:
		return "";
	
	case EPocoContentTypes::Video_WMV:
		return "";
	
	default:
		return "text/plain";
	}
}

bool UHttpRequestPoco::SendResponse_String(TMap<FString, FString> In_Headers, FString In_Response, EPocoStatusCodes In_Status, EPocoContentTypes In_ContentTypes, bool bChunkedTransferEncoding)
{
	if (!this->HTTP_Request)
	{
		return false;
	}

	this->HTTP_Response->setChunkedTransferEncoding(true);
	this->HTTP_Response->setContentType(this->ConvertToPocoMime(In_ContentTypes));
	this->HTTP_Response->setStatus(this->ConvertToPocoStatus(In_Status));

	for (TPair<FString, FString> EachHeader : In_Headers)
	{
		this->HTTP_Response->add(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	std::string ResponseString = TCHAR_TO_UTF8(*In_Response);

	this->HTTP_Response->send()
		<< ResponseString;

	return true;
}

bool UHttpRequestPoco::GetRequestQuery(TMap<FString, FString>& Out_Query, FString& Query_Title)
{
	if (!this->HTTP_Request)
	{
		return false;
	}

	TArray<FString> Sections_Uri = UKismetStringLibrary::ParseIntoArray(this->RequestUri, "/");
	
	// We need to check if request uri is only root or not.
	if (Sections_Uri.IsEmpty())
	{
		return false;
	}

	FString LastSection = Sections_Uri.Last();

	// Correct query contains "?" in it.
	if (!LastSection.Contains("?"))
	{
		return false;
	}

	TArray<FString> Sections_Query = UKismetStringLibrary::ParseIntoArray(LastSection, "?");
	int SectionSize = Sections_Query.Num();

	// If URI contains multiple param declaration or doesn't contain at all, return false. 
	if (SectionSize == 0 || SectionSize > 2)
	{
		return false;
	}

	FString SourceString;
	if (SectionSize == 1)
	{
		SourceString = Sections_Query[0];
	}

	// Sometimes query contains title like "/params?color=blue".
	else if (SectionSize == 2)
	{
		Query_Title = Sections_Query[0];
		SourceString = Sections_Query[1];
	}

	// Check if there are multiple parameter for query.
	if (SourceString.Contains("&"))
	{
		TArray<FString> Sections_Query_Params = UKismetStringLibrary::ParseIntoArray(SourceString, "&");

		if (Sections_Query_Params.IsEmpty())
		{
			return false;
		}

		TMap<FString, FString> TempQueries;
		for (FString EachParamPair : Sections_Query_Params)
		{
			TArray<FString> ParamPairArray = UKismetStringLibrary::ParseIntoArray(EachParamPair, "=");

			if (ParamPairArray.Num() != 2)
			{
				continue;
			}

			FString Key = ParamPairArray[0];
			FString Value = ParamPairArray[1];

			TempQueries.Add(Key, Value);
		}

		Out_Query = TempQueries;
	}

	else
	{
		TArray<FString> ParamPairArray = UKismetStringLibrary::ParseIntoArray(SourceString, "=");

		if (ParamPairArray.Num() != 2)
		{
			return false;
		}

		FString Key = ParamPairArray[0];
		FString Value = ParamPairArray[1];

		Out_Query.Add(Key, Value);
	}

	return true;
}

bool UHttpRequestPoco::GetHeaders(TMap<FString, FString>& Out_Headers)
{
	if (!this->HTTP_Request)
	{
		return false;
	}

	NameValueCollection NVC(*this->HTTP_Request);
	
	TMap<FString, FString> MAP_Temp;
	for (NameValueCollection::ConstIterator Each_Header = NVC.begin() ; Each_Header != NVC.end() ; ++Each_Header)
	{
		FString Key = Each_Header._Ptr->first.c_str();
		FString Value = Each_Header._Ptr->second.c_str();

		MAP_Temp.Add(Key, Value);
	}

	Out_Headers = MAP_Temp;
	
	return true;
}

bool UHttpRequestPoco::GetBody(FString& Out_Body)
{
	if (!this->HTTP_Request)
	{
		return false;
	}

	std::istream& HTTP_Stream = this->HTTP_Request->stream();
	const size_t HTTP_Content_Lenght = this->HTTP_Request->getContentLength();
	std::string HTTP_Content_Buffer(HTTP_Content_Lenght, 0);
	HTTP_Stream.read(HTTP_Content_Buffer.data(), HTTP_Content_Lenght);

	if (HTTP_Content_Buffer.empty())
	{
		return false;
	}

	Out_Body = HTTP_Content_Buffer.c_str();

	return true;
}