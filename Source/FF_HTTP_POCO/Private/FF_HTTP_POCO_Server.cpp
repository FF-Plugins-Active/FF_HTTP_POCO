// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_POCO_Server.h"
#include "Classes/Request_Handler_Factory.h"

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
	this->POCO_Server_Params = new HTTPServerParams;
	this->POCO_Server_Params->setMaxThreads(this->ThreadNum);

	Poco::ThreadPool& ThreadPool = Poco::ThreadPool::defaultPool();
	ThreadPool.addCapacity(this->ThreadNum);

	const ServerSocket PocoServerSocket(this->Port_HTTP);

	ReqHandlerFactory* HandlerFactory = new ReqHandlerFactory;
	HandlerFactory->Owner = this;

	this->POCO_Server = Poco::makeShared<HTTPServer>(HandlerFactory, ThreadPool, PocoServerSocket, POCO_Server_Params);

	try
	{
		this->POCO_Server->start();
	}

	catch (Poco::Exception& Exception)
	{
		FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("FF HTTP POCO : Thread->Callback_HTTP_Start : %s"), *ExceptionString);

		return false;
	}

	return true;
}

void AHTTP_Server_POCO::HTTP_Server_Stop()
{
	try
	{
		if (!this->POCO_Server.isNull())
		{
			this->POCO_Server->stopAll(true);
			this->POCO_Server.reset();
		}

		if (!this->POCO_Server_Params)
		{
			delete(&this->POCO_Server_Params);
		}
	}

	catch (Poco::Exception& Exception)
	{
		FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("FF HTTP POCO : Thread->Callback_HTTP_Stop: %s"), *ExceptionString);

		return;
	}
}