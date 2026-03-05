// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Coldsnap/UpgradeGameplayEffect.h"
#include "PersistentUpgradeGameplayEffect.generated.h"

/**
 * Upgrade effects that will be carried between scenes by the player (should be all except fuel heal effect)
 *
 * Jeff Stevenson
 * 3.4.26
 */

UCLASS()
class COLDSNAP_API UPersistentUpgradeGameplayEffect : public UUpgradeGameplayEffect
{
	GENERATED_BODY()

	UPersistentUpgradeGameplayEffect(const FObjectInitializer& ObjectInitializer);
};
