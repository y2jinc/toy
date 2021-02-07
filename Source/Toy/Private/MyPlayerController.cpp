// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyObject.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//TestMyObject = NewObject<UMyObject>(this);	

	TestMyInfo.Object = NewObject<UMyObject>(this);

	//MyNativeInfo.Object2 = NewObject<UMyObject>(this);
}

void AMyPlayerController::TestGarbageCollect()
{
	TryCollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS, true);

	if (!TestMyInfo.Object->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("invalid myobject"));
	}

	//if (!MyNativeInfo.Object2->IsValidLowLevel())
	//{
	//	UE_LOG(LogTemp, Error, TEXT("invalid MyNativeInfo"));
	//}	
}