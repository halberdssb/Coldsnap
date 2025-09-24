// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IHittable.generated.h"

/**
 * 
 */

UINTERFACE(MinimalAPI, Blueprintable)
class UHittable: public UInterface
{
	GENERATED_BODY()
};

class COLDSNAP_API IHittable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Hit")
	void Hit();
};
