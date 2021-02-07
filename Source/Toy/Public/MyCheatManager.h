// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "MyCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class TOY_API UMyCheatManager : public UCheatManager
{
	GENERATED_BODY()
	
	/** edit me for viewing property window. */
	UFUNCTION(exec, BlueprintCallable, Category = "My Cheat Manager")
	virtual void EditMe();

	UFUNCTION(exec, BlueprintCallable, Category = "My Cheat Manager")
	virtual void SearchActor();

	UFUNCTION(exec, BlueprintCallable, Category = "My Cheat Manager")
	virtual void SearchObject();

private:
	TSharedPtr<class SSearchObjectBox> SearchObjectBox;
};
