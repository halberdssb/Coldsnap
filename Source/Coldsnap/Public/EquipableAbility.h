// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "EquipableAbility.generated.h"

/**
 * Base class for gameplay abilities that can be equipped/unequipped by items
 *
 * Jeff Stevenson
 * 11.7.25
 */
UCLASS()
class COLDSNAP_API UEquipableAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	FString AbilityName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	FString AbilityDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	float HeatCost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	float Cooldown;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	UClass* PickupActor;
};
