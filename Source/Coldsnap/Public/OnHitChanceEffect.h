// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "FOnHitInfo.h"
#include "Coldsnap/UpgradeGameplayEffect.h"
#include "OnHitChanceEffect.generated.h"

/**
 * Upgrade type for a specific on-hit effect to occur
 * *** CURRENTLY DEPRECATED - using abilities fired by tag events that handle proc chance - see ProcChanceGameplayAbility ***
 *
 * Jeff Stevenson
 * 1.25.26
 */

UCLASS()
class COLDSNAP_API UOnHitChanceEffect : public UUpgradeGameplayEffect
{
	GENERATED_BODY()

public:
	// chance for effect to occur
	UPROPERTY(EditAnywhere)
	float ProcChance;
	// effect to proc
	UPROPERTY(EditAnywhere)
	UUpgradeGameplayEffect* ProcEffect;
	// rolls random value to see if effect procs 
	UFUNCTION(BlueprintCallable, Category = "OnHitChanceEffect")
	void RollOnHitChanceEffeect(FOnHitInfo HitInfo);
	
};
