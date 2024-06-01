#include "FF_HTTP_POCO_Request.h"

bool UHttpRequestPoco::SendResponse(FString In_Response)
{
	if (!this->HTTP_Request)
	{
		return false;
	}

	this->HTTP_Response->setChunkedTransferEncoding(true);
	this->HTTP_Response->setContentType("text/html"s);

	this->HTTP_Response->send()
		<< "<html>"
		<< "<head><title>Hello</title></head>"
		<< "<body><h1>Hello from the POCO Web Server</h1></body>"
		<< "</html>";

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