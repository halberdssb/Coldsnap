// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "UObject/NoExportTypes.h"
#include "COLDSNAPGameInstance.generated.h"

/**
 * Custom GameInstance class that handles saving player and settings data
 *
 * Jeff Stevenson
 * 1.18.26
 */

UCLASS(Blueprintable)
class COLDSNAP_API UCOLDSNAPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void SavePlayerGASData(TArray<FGameplayEffectSpec> InActiveGameplayEffects);
	TArray<FGameplayEffectSpec> LoadPlayerGASData();

private:
	TArray<FGameplayEffectSpec> ActiveGameplayEffects;
};
