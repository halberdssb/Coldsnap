// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayerMovementAttributeSet.h"
#include "HeatAttributeSet.generated.h"

/**
 * Heat attributes for player heat meter & abilities
 *
 * Jeff Stevenson
 * 10.25.25
 */

UCLASS()
class COLDSNAP_API UHeatAttributeSet : public UAttributeSet
{
public:
	GENERATED_BODY()

	UHeatAttributeSet();

	// handles clamping heat to min and max values when changed
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	// Current heat value that keeps track of current heat meter amount held by actor
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Heat;
	// maximum heat value the player/actor can have
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxHeat;
	// heat gain multiplier
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData HeatGainMultiplier;
	// heat drain base value
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData HeatDrainValue;
	// heat drain multiplier
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData HeatDrainMultiplier;

	// GAS attribute accessors
	ATTRIBUTE_ACCESSORS_BASIC(UHeatAttributeSet, Heat);
	ATTRIBUTE_ACCESSORS_BASIC(UHeatAttributeSet, MaxHeat);
	ATTRIBUTE_ACCESSORS_BASIC(UHeatAttributeSet, HeatGainMultiplier);
	ATTRIBUTE_ACCESSORS_BASIC(UHeatAttributeSet, HeatDrainValue);
	ATTRIBUTE_ACCESSORS_BASIC(UHeatAttributeSet, HeatDrainMultiplier);
	
	// attribute changed functions
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	// attribute changed delegates
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHeatChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnMaxHeatChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHeatGainMultiplierChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHeatDrainValueChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHeatDrainMultiplierChanged;
	
private:
	float BaseHeat = 0;
	float BaseMaxHeat = 100;
	float BaseHeatGainMultiplier = 1;
	float BaseHeatDrainValue = -1;
	float BaseHeatDrainMultiplier = 1;
};
