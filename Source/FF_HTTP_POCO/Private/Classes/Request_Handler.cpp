#include "Classes/Request_Handler.h"

bool ReqHandler::IsApiRequest(FString InReqUri)
{
	TArray<FString> Sections_URI_Api = UKismetStringLibrary::ParseIntoArray(this->Owner->API_URI, "/");
	TArray<FString> Sections_URI_Req = UKismetStringLibrary::ParseIntoArray(InReqUri, "/");

	if (Sections_URI_Api.Num() > Sections_URI_Req.Num())
	{
		return false;
	}

	for (int32 Index_Section = 0; Index_Section < Sections_URI_Api.Num(); Index_Section++)
	{
		if (Sections_URI_Req[Index_Section] != Sections_URI_Api[Index_Section])
		{
			return false;
		}
	}

	return true;
}

void ReqHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	if (!this->Owner)
	{
		return;
	}

	try
	{
		FString RequestUri = request.getURI().c_str();

		if (this->IsApiRequest(RequestUri))
		{
			UHttpRequestPoco* RequestObject = NewObject<UHttpRequestPoco>();
			RequestObject->HTTP_Request = &request;
			RequestObject->HTTP_Response = &response;
			RequestObject->RequestUri = RequestUri;

			this->Owner->DelegateHttpRequest.Broadcast(RequestObject);

			return;
		}

		else
		{
			response.setChunkedTransferEncoding(true);
			response.setContentType("text/html");

			std::string ResponseString = TCHAR_TO_UTF8(*this->Owner->API_URI);

			response.send()
				<< "<html>"
				<< "<head><title>UE5 POCO C++ Server</title></head>"
				<< "<body><h1> Please use correct API URL = " + ResponseString + "</h1></body>"
				<< "</html>";
		}
	}

	catch (Poco::Exception& Exception)
	{
		FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("FF HTTP POCO : Thread->handleRequest : %s"), *ExceptionString);

		return;
	}
}