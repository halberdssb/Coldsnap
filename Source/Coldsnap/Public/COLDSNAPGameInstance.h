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
	// takes in GAS data (typically from GAS data handler) and saves it to instance
	void SavePlayerGASData(TArray<FGameplayEffectSpec> InActiveGameplayEffects, float InCurrentHealth);
	TArray<FGameplayEffectSpec> LoadPlayerGASData(float& OutCurrentHealth);

	void Init() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Run Data")
	float RunStartTime;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Run Data")
	int StagesCleared;
	// sets current saved health of player
	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(float InCurrentHealth);
	// returns last saved health of player
	UFUNCTION(BlueprintCallable)
	const float GetCurrentHealth();
	// resets data between runs
	UFUNCTION(BlueprintCallable)
	void ResetRunData();

private:
	TArray<FGameplayEffectSpec> ActiveGameplayEffects;
	float CurrentHealth = 200;
	const float DefaultHealth = 200;
};
