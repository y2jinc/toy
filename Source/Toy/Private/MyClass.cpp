// Fill out your copyright notice in the Description page of Project Settings.


#include "MyClass.h"

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

void FMyInfo::AddStructReferencedObjects(class FReferenceCollector& Collector) const
{
	if (Object)
		Collector.AddReferencedObject(const_cast<UMyObject*>(Object));
}

void FMyNativeInfo::AddReferencedObjects(FReferenceCollector & Collector)
{
	if (Object2)
		Collector.AddReferencedObject(Object2);
}

