// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IHittable.generated.h"

/**
 * (U) Interface for hittable actors
 *
 * Jeff Stevenson
 * 10.24.25
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
	// overrideable hit function - called by attacks/hit sources when actor is hit
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Hit")
	void Hit(bool stunEnemy, float damage, FVector knockbackForce);
};
