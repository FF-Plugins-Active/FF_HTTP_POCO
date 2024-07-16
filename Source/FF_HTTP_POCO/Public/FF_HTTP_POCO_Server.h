// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_POCO_Request.h"

#include "FF_HTTP_POCO_Server.generated.h"

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;

UCLASS()
class FF_HTTP_POCO_API AHTTP_Server_POCO : public AActor
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called when the game end or when destroyed.
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	Poco::SharedPtr<HTTPServer> POCO_Server;

public:	

	// Sets default values for this actor's properties.
	AHTTP_Server_POCO();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|POCO")
	FDelegateRequestPoco DelegateHttpRequest;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString API_URI = "api/poco/v1";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 ThreadNum = 4;

public:

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|POCO")
	void OnHttPoco_Start();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|POCO")
	void OnHttPoco_Stop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|POCO")
	void OnHttPoco_Request(UHttpRequestPoco* Request);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Start"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Stop"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual void HTTP_Server_Stop();

};