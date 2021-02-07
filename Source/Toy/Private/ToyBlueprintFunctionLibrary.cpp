// Fill out your copyright notice in the Description page of Project Settings.


#include "ToyBlueprintFunctionLibrary.h"

void UToyBlueprintFunctionLibrary::GetAllAnimationSequencesReferred(UAnimMontage* InAnimMontage, TArray<UAnimationAsset*>& AnimationAssets)
{
	if (!InAnimMontage)
	{
		return;
	}

	InAnimMontage->GetAllAnimationSequencesReferred(AnimationAssets);
}