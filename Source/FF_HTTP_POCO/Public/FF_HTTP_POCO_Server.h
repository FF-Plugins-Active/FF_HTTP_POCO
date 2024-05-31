// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Threads.
#include "FF_HTTP_POCO_Thread.h"

#include "FF_HTTP_POCO_Server.generated.h"

UCLASS(BlueprintType)
class FF_HTTP_POCO_API UHttpRequestPoco : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse(FString In_Response = "<html>Hello World!</html>");

	UFUNCTION(BlueprintCallable)
	virtual bool GetRequestUri(FString& Out_Uri);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRequestPoco, UHttpRequestPoco*, Request);

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

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "If you want to change API parameter, just put /* to the end. If you don't do that, server won't detect dynamic API requests.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString API_URI = "api/poco/v1/*";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|POCO")
	FString Server_Name = "";

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Start"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Stop"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server POCO - Toggle"), Category = "Frozen Forest|HTTP|Server|POCO")
	virtual bool HTTP_Server_Toggle(bool bIsPause);

};