// Copyright 2025 Icebreak Studios. All rights reserved.

#include "FEquippedUpgradeData.h"

FEquippedUpgradeData::FEquippedUpgradeData()
{
	PickupObjectClass = nullptr;
	EquippedEffect = nullptr;
}

FEquippedUpgradeData::FEquippedUpgradeData(TSubclassOf<AActor> InPickupObjectClass,	TSubclassOf<UUpgradeGameplayEffect> InEquippedEffect)
{
	PickupObjectClass = InPickupObjectClass;
	EquippedEffect = InEquippedEffect;
}
