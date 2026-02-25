// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayAbilityInputData.h"
#include "PlayerAbilitySystemComponent.generated.h"

/*
 * Custom Player Ability System Component
 *
 * Jeff Stevenson
 * 10.24.25
 */
UCLASS()
class COLDSNAP_API UPlayerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UPlayerAbilitySystemComponent();

	// input action to ability mapping asset
	UPROPERTY(EditAnywhere)
	UGameplayAbilityInputData* AbilityInputMappings;

	// specs of mapped abilities
	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	TArray<FGameplayAbilitySpecHandle> MappedAbilitySpecHandles;

	// returns all mapped gameplay ability specs
	UFUNCTION(BlueprintCallable, Category = "Data Persistence")
	TArray<FGameplayEffectSpec> GetAllAppliedGameplayEffectSpecs();

protected:
	// array of all applied upgrades - used to keep track btw scenes
	TArray<FGameplayEffectSpec> AppliedUpgradeEffects;

	// checks if new effect is upgrade and adds to tracking array if so
	UFUNCTION()
	void AddGameplayEffectToAppliedEffectsArray(UAbilitySystemComponent* InASC, const FGameplayEffectSpec& InEffectSpec, FActiveGameplayEffectHandle InEffectHandle);
};
