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
	
	// Current heat value that keeps track of current heat meter amount held by actor
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Heat;
	// maximum heat value the player/actor can have
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxHeat;

	ATTRIBUTE_ACCESSORS_BASIC(UHeatAttributeSet, Heat);
	ATTRIBUTE_ACCESSORS_BASIC(UHeatAttributeSet, MaxHeat);
	
	// attribute changed functions
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHeatChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnMaxHeatChanged;
	
private:
	float BaseHeat = 0;
	float BaseMaxHeat = 100;
};
