// Copyright Epic Games, Inc. All Rights Reserved.

#include "FF_HTTP_POCO.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FFF_HTTP_WFModule"

void FFF_HTTP_POCOModule::StartupModule()
{
#ifdef _WIN64

	const FString BasePluginDir = IPluginManager::Get().FindPlugin("FF_HTTP_POCO")->GetBaseDir();
	const FString DLL_Path = FPaths::Combine(*BasePluginDir, TEXT("Source/POCO/Win64/bin/"));

	this->PocoActiveRecord = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoActiveRecord.dll")));
	this->PocoData = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoData.dll")));
	this->PocoDataODBC = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoDataODBC.dll")));
	this->PocoEncodings = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoEncodings.dll")));
	this->PocoFoundation = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoFoundation.dll")));
	this->PocoJSON = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoJSON.dll")));
	this->PocoNet = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoNet.dll")));
	this->PocoPrometheus = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoPrometheus.dll")));
	this->PocoUtil = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoUtil.dll")));
	this->PocoXML = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoXML.dll")));
	this->PocoZip = FPlatformProcess::GetDllHandle(*FPaths::Combine(*DLL_Path, TEXT("PocoZip.dll")));


	if (this->PocoActiveRecord == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoActiveRecord.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoData == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoData.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoDataODBC == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoDataODBC.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoEncodings == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoEncodings.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoFoundation == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoFoundation.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoJSON == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoJSON.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoNet == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoNet.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoPrometheus == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoPrometheus.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoUtil == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoUtil.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoXML == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoXML.dll failed to load for FF_HTTP_POCO plugin !"));
	}

	if (this->PocoZip == nullptr)
	{
		UE_LOG(LogTemp, Fatal, TEXT("PocoZip.dll failed to load for FF_HTTP_POCO plugin !"));
	}

#endif
}

void FFF_HTTP_POCOModule::ShutdownModule()
{
#ifdef _WIN64
	
	FPlatformProcess::FreeDllHandle(this->PocoActiveRecord);
	this->PocoActiveRecord = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoData);
	this->PocoData = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoDataODBC);
	this->PocoDataODBC = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoEncodings);
	this->PocoEncodings = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoFoundation);
	this->PocoFoundation = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoJSON);
	this->PocoJSON = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoNet);
	this->PocoNet = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoPrometheus);
	this->PocoPrometheus = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoUtil);
	this->PocoUtil = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoXML);
	this->PocoXML = nullptr;

	FPlatformProcess::FreeDllHandle(this->PocoZip);
	this->PocoZip = nullptr;

#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFF_HTTP_POCOModule, FF_HTTP_POCO)