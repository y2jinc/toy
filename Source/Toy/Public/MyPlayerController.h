// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyClass.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOY_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	/** Pause the game for Delay seconds. */
	UFUNCTION(exec, BlueprintCallable, Category = "MyPlayerController")
	virtual void TestGarbageCollect();

public:
	UPROPERTY()
	class UMyObject* TestMyObject;

	UPROPERTY()
	FMyInfo TestMyInfo;

	//FMyNativeInfo MyNativeInfo;
};

