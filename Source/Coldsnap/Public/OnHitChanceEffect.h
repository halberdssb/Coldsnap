// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "FOnHitInfo.h"
#include "Coldsnap/UpgradeGameplayEffect.h"
#include "OnHitChanceEffect.generated.h"

/**
 * Upgrade type for a specific on-hit effect to occur
 *
 * Jeff Stevenson
 * 1.25.26
 */

UCLASS()
class COLDSNAP_API UOnHitChanceEffect : public UUpgradeGameplayEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float ProcChance;
	UPROPERTY(EditAnywhere)
	UUpgradeGameplayEffect* ProcEffect;
	UFUNCTION(BlueprintCallable, Category = "OnHitChanceEffect")
	void RollOnHitChanceEffeect(FOnHitInfo HitInfo);
	
};
