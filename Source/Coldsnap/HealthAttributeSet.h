// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
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
	
	// Current health - used for dealing damage/healing/etc
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Health;

	// Maximum health - should not be changed by damage/other temporary values, only max health changes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, Health);
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, MaxHealth);
};
