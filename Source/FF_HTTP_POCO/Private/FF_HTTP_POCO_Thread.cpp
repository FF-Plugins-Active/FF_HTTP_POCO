// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_POCO_Thread.h"
#include "FF_HTTP_POCO_Server.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_POCO::FHTTP_Thread_POCO(AHTTP_Server_POCO* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Port_HTTP = this->Parent_Actor->Port_HTTP;
	this->Port_HTTPS = this->Parent_Actor->Port_HTTPS;

	this->RunnableThread = FRunnableThread::Create(this, *this->Parent_Actor->Server_Name);
}

FHTTP_Thread_POCO::~FHTTP_Thread_POCO()
{
	if (this->RunnableThread)
	{
		this->RunnableThread->Kill(true);
		delete this->RunnableThread;
	}
}

bool FHTTP_Thread_POCO::Init()
{	
	this->Callback_HTTP_Start();
	this->bStartThread = true;

	return true;
}

uint32 FHTTP_Thread_POCO::Run()
{
	while (this->bStartThread)
	{
		//FDateTime Now;
		//UE_LOG(LogTemp, Display, TEXT("Workflow server is running : %s"), *Now.ToString());
	}

	return 0;
}

void FHTTP_Thread_POCO::Stop()
{
	this->Callback_HTTP_Stop();
	
	this->bStartThread = false;
}

bool FHTTP_Thread_POCO::Toggle(bool bIsPause)
{
	if (!this->RunnableThread)
	{
		return false;
	}

	this->RunnableThread->Suspend(bIsPause);
	
	return true;
}

void FHTTP_Thread_POCO::Callback_HTTP_Start()
{	
	auto Callback = [this]()
	{

	};
}

void FHTTP_Thread_POCO::Callback_HTTP_Stop()
{

}