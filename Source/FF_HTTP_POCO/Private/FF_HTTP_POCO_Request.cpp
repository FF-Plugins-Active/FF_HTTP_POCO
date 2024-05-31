#include "FF_HTTP_POCO_Request.h"

bool UHttpRequestPoco::SendResponse(FString In_Response)
{
	this->HTTP_Response->setChunkedTransferEncoding(true);
	this->HTTP_Response->setContentType("text/html"s);

	this->HTTP_Response->send()
		<< "<html>"
		<< "<head><title>Hello</title></head>"
		<< "<body><h1>Hello from the POCO Web Server</h1></body>"
		<< "</html>";

	return true;
}

bool UHttpRequestPoco::GetRequestUri(FString& Out_Uri)
{
	return false;
}

bool UHttpRequestPoco::GetHeaders(TMap<FString, FString>& Out_Headers)
{
	NameValueCollection NameValueCollection(*this->HTTP_Response);

	TMap<FString, FString> MAP_Temp;
	for (std::pair<std::string, std::string> EachItem : NameValueCollection)
	{
		FString Key = EachItem.first.c_str();
		FString Value = EachItem.second.c_str();

		MAP_Temp.Add(Key, Value);
	}

	Out_Headers = MAP_Temp;

	return true;
}