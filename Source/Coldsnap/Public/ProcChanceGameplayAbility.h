// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ProcChanceGameplayAbility.generated.h"

/**
 * Ability that has a chance to activate based on a certain condition
 *
 * Jeff Stevenson
 * 1.24.25
 */
UCLASS()
class COLDSNAP_API UProcChanceGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	// chance for ability to proc
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Proc Chance", meta=(ClampMin = "0.0", UIMin = "0.0", ClampMax = "1.0", UIMax = "1.0"))
	float ProcChance;
	// rolls chance to proc when ability is fired
	UFUNCTION(BlueprintCallable, Category = "ProcChance")
	bool IsAbilityProcced();
};
