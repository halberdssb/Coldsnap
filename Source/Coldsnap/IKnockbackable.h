// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IKnockbackable.generated.h"

/**
 * (U)Interface for actors that can receive knockback from attacks - MUST also be IHittable to be hit
 *
 * Jeff Stevenson
 * 10.24.25
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

	// Overrideable function to receive knockback - called by attacks/knockback appliers on all hit IKnockbackable actors
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Knockback")
	void ApplyKnockback(FVector knockbackDirection, float knockbackForce);
};
