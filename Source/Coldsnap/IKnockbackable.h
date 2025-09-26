// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IKnockbackable.generated.h"

/**
 * 
 */

UINTERFACE(MinimalAPI, Blueprintable)
class UKnockbackable: public UInterface
{
	GENERATED_BODY()
};

class COLDSNAP_API IKnockbackable
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Knockback")
	void ApplyKnockback(FVector knockbackDirection, float knockbackForce);
};
