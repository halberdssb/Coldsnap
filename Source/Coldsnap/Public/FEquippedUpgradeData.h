// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once
#include "PersistentUpgradeGameplayEffect.h"
#include "Coldsnap/UpgradeGameplayEffect.h"
#include "FEquippedUpgradeData.generated.h"

/*
 * Stored data for an upgrade once equipped (used for player inventory)
 *
 * Jeff Stevenson
 * 11.15.25
 */

UENUM(BlueprintType, Category = "Upgrades")
enum EUpgradeEquipLocation
{
	Arms,
	Legs,
	Torso,
	Fuel
};

USTRUCT(BlueprintType)
struct FEquippedUpgradeData
{

public:

	GENERATED_BODY()

	// constructors
	FEquippedUpgradeData();
	
	FEquippedUpgradeData(TSubclassOf<AActor> InPickupObjectClass, TSubclassOf<UUpgradeGameplayEffect> InEquippedEffect);
	
	// actor class of upgrade pickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> PickupObjectClass;

	// how upgrade is equipped
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EUpgradeEquipLocation> EquipLocation;

	// equipped effect of upgrade
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UPersistentUpgradeGameplayEffect> EquippedEffect;

	// Hash fields for TMap compatability:
	
	// equals and not equals operator implementation
	bool operator==(const FEquippedUpgradeData& Other) const
	{
		return PickupObjectClass == Other.PickupObjectClass && EquippedEffect == Other.EquippedEffect;
	}

	bool operator!=(const FEquippedUpgradeData& Other) const
	{
		return !operator==(Other);
	}
	
	// checks if pickup class and effect are valid
	bool IsValid() const
	{
		return PickupObjectClass && EquippedEffect;
	}

	// Hash type pairing for TMap pairing
	friend uint32 GetTypeHash(const FEquippedUpgradeData& Item)
	{
		return HashCombine(GetTypeHash(Item.PickupObjectClass), GetTypeHash(Item.EquippedEffect));
	}
};
