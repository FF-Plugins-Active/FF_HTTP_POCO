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

	void* PocoFoundation = nullptr;
	void* PocoNet = nullptr;
	void* PocoUtil = nullptr;
	void* PocoData = nullptr;
	void* PocoDataODBC = nullptr;
	void* PocoEncodings = nullptr;

#endif

};
