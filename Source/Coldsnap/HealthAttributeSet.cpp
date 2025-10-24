// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayEffectExtension.h"
#include "HealthAttributeSet.h"

/*
 * GAS Attribute Set for health
 * 
 * Jeff Stevenson
 * 10.24.25
 */

UHealthAttributeSet::UHealthAttributeSet()
{
	//InitHealth(100.0f);
	//InitMaxHealth(100.0f);
}

void UHealthAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		// Deal damage to player health and clamp to between min and max health values
		const float DamageValue = GetDamage();
		const float OldHealthValue = GetHealth();
		const float MaxHealthValue = GetMaxHealth();
		const float NewHealthValue = FMath::Clamp(OldHealthValue - DamageValue, 0.0f, MaxHealthValue);

		// Apply to current health if new health is different
		if (OldHealthValue != NewHealthValue)
		{
			SetHealth(NewHealthValue);
		}

		// Set Damage back to 0
		SetDamage(0);
	}
}

void UHealthAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	
}

void UHealthAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	if (Attribute == GetMaxHealthAttribute())
	{
		float OldHealthDifference = OldValue - GetHealth();
		SetHealth(NewValue - OldHealthDifference);
	}
}

