// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthAttributeSet.h"
#include "GameplayEffectExtension.h"

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
			OnHealthChanged.Broadcast(this, OldHealthValue, NewHealthValue);
		}

		// Set Damage back to 0
		SetDamage(0);
	}
}

void UHealthAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHealth());
	}
}

void UHealthAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	if (Attribute == GetHealthAttribute())
	{
		OnHealthChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		OnMaxHealthChanged.Broadcast(this, OldValue, NewValue);
		float OldHealthDifference = OldValue - GetHealth();
		SetHealth(NewValue - OldHealthDifference);
	}
}

