// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ToyBlueprintFunctionLibrary.generated.h"

class UAnimationAsset;
class UAnimMontage;

/**
 * 
 */
UCLASS()
class TOY_API UToyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Animation | Toy")
	static void GetAllAnimationSequencesReferred(UAnimMontage* InAnimMontage, TArray<UAnimationAsset*>& AnimationAssets);
};
