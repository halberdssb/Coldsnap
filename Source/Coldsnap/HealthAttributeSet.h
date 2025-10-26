// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayerMovementAttributeSet.h"
#include "HealthAttributeSet.generated.h"

/*
 * GAS Attribute Set for health
 * 
 * Jeff Stevenson
 * 10.24.25
 */

UCLASS()
class COLDSNAP_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UHealthAttributeSet();

	// Handles dealing damage to health when damage is dealt
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	// Damage value - used to deal damage to health using meta attribute
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Damage;
	// Current health - used for dealing damage/healing/etc
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Health;

	// Maximum health - should not be changed by damage/other temporary values, only max health changes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;

	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, Damage);
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, Health);
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, MaxHealth);

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnMaxHealthChanged;
	
	// attribute changed functions
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
};
