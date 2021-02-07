// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCheatManager.h"
#include "../Slate/SSearchObjectBox.h"


void UMyCheatManager::EditMe()
{
	FString cmd = FString::Printf(TEXT("EditActor name=%s"), *GetOuterAPlayerController()->GetPawn()->GetName());
	GEngine->Exec(GetOuterAPlayerController()->GetPawn()->GetWorld(), *cmd);
}

void UMyCheatManager::SearchActor()
{
	// create Slate property window
	FSlateApplication::Get().AddWindow
	(
		SNew(SWindow)
		.ClientSize(FVector2D(600, 600))
		.Title(FText::FromString("Search Actor"))
		[
			SAssignNew(SearchObjectBox, SSearchObjectBox, GetWorld())
			.bSearchActor(true)
		]
	);
}


void UMyCheatManager::SearchObject()
{
	// create Slate property window
	FSlateApplication::Get().AddWindow
	(
		SNew(SWindow)
		.ClientSize(FVector2D(600, 600))
		.Title(FText::FromString("Search Object"))
		[
			SAssignNew(SearchObjectBox, SSearchObjectBox, GetWorld())
			.bSearchActor(false)
		]
	);
}