// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Threads.
#include "FF_HTTP_POCO_Thread.h"
#include "FF_HTTP_POCO_Request.h"
#include "FF_HTTP_POCO_Server.generated.h"

UCLASS()
class FF_HTTP_POCO_API AHTTP_Server_POCO : public AActor
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called when the game end or when destroyed.
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	

	// Sets default values for this actor's properties.
	AHTTP_Server_POCO();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

#ifdef _WIN64
	class FHTTP_Thread_POCO* Thread_POCO = nullptr;
#endif

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|POCO")
	void OnHttPoco_Start();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|POCO")
	void OnHttPoco_Stop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|POCO")
	void OnHttPoco_Request(UHttpRequestPoco* Request);

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|POCO")
	FDelegateRequestPoco DelegateHttpRequest;

public:

#if (ENABLE_SERVE_STATIC_PAGE == 1)

	// Delete comment lines of UPROPERTYs

	//UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "Don't put \"/\" at the end.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString Server_Path_Root = "";

	//UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It has to be either in root or one of the subfolder of root and put \"/\" as prefix.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString Server_Path_404 = "/404.html";

	//UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "Put \"/\" as prefix.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString Server_Path_Index = "/index.html";
#endif

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString API_URI = "api/poco/v1";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString Server_Name = "SRV_POCO_";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 ThreadNum = 4;

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Start"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Stop"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Toggle"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual bool HTTP_Server_Toggle(bool bIsPause);

};