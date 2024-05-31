// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_POCO_Server.h"

// Sets default values
AHTTP_Server_POCO::AHTTP_Server_POCO()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned.
void AHTTP_Server_POCO::BeginPlay()
{
#ifdef _WIN64
	this->HTTP_Server_Start();
#endif
	
	Super::BeginPlay();
}

// Called when the game end or when destroyed.
void AHTTP_Server_POCO::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#ifdef _WIN64
	this->HTTP_Server_Stop();
#endif

	Super::EndPlay(EndPlayReason);
}

// Called every frame.
void AHTTP_Server_POCO::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHTTP_Server_POCO::HTTP_Server_Start()
{
#ifdef _WIN64
	
	if (this->Server_Name.IsEmpty())
	{
		return false;
	}

	this->Thread_POCO = new FHTTP_Thread_POCO(this);

	if (this->Thread_POCO)
	{
		return true;
	}

	else
	{
		return false;
	}

#else

	return false;

#endif
}

void AHTTP_Server_POCO::HTTP_Server_Stop()
{
#ifdef _WIN64
	
	if (this->Thread_POCO)
	{
		delete this->Thread_POCO;
		return;
	}

	else
	{
		return;
	}

#else

#endif
}

bool AHTTP_Server_POCO::HTTP_Server_Toggle(bool bIsPause)
{
	if (!this->Thread_POCO)
	{
		return false;
	}

	return this->Thread_POCO->Toggle(bIsPause);
}