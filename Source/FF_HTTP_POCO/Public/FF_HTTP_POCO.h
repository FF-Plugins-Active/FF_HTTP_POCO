// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FFF_HTTP_POCOModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#ifdef _WIN64

	void* PocoActiveRecord = nullptr;
	void* PocoData = nullptr;
	void* PocoDataODBC = nullptr;
	void* PocoEncodings = nullptr;
	void* PocoFoundation = nullptr;
	void* PocoJSON = nullptr;
	void* PocoNet = nullptr;
	void* PocoPrometheus = nullptr;
	void* PocoUtil = nullptr;
	void* PocoXML = nullptr;
	void* PocoZip = nullptr;

#endif

};
