// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/GCObject.h"
#include "UObject/Class.h"
#include "MyClass.generated.h"

USTRUCT()
struct FMyInfo
{
	FMyInfo() : Object(nullptr) {}

	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FString MyInfoName;

	UPROPERTY()
	class UMyObject* Object;

	void AddStructReferencedObjects(class FReferenceCollector& Collector) const;
};

template<>
struct TStructOpsTypeTraits<FMyInfo> : public TStructOpsTypeTraitsBase2<FMyInfo>
{
	enum
	{
//		WithCopy = true,		// Necessary so that TSharedPtr<FRootMotionSource> Data is copied around
//		WithNetSerializer = true,
//		WithIdenticalViaEquality = true,
		WithAddStructReferencedObjects = true,
	};
};


struct FMyNativeInfo : public FGCObject
{
	FMyNativeInfo() {}
	~FMyNativeInfo() {}
	//~ Begin FGCObject implementation
	virtual void AddReferencedObjects(FReferenceCollector & Collector) override;
	//~ End FGCObject implementation

	class UMyObject* Object2;
};

/**
 * 
 */
class TOY_API MyClass
{
public:
	MyClass();
	~MyClass();
};
