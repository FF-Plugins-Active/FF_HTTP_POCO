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
	if (!this->HTTP_Request)
	{
		return false;
	}

	Out_Uri = this->HTTP_Request->getURI().c_str();

	return false;
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