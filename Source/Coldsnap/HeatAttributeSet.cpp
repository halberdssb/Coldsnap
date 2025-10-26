// Copyright 2025 Icebreak Studios. All rights reserved.


#include "HeatAttributeSet.h"

#include "GameplayEffectExtension.h"

/**
 * Heat attributes for player heat meter & abilities
 *
 * Jeff Stevenson
 * 10.25.25
 */

UHeatAttributeSet::UHeatAttributeSet()
{
	InitHeat(BaseHeat);
	InitMaxHeat(BaseMaxHeat);
	InitHeatGainMultiplier(BaseHeatGainMultiplier);
}

void UHeatAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHeatAttribute())
	{		
		float CurrentHeat = GetHeat();

		// multiply by heat gain mult if gain was positive
		if (Data.EvaluatedData.Magnitude > 0)
		{
			CurrentHeat *= GetHeatGainMultiplier();
		}
		float NewHeatValue = FMath::Clamp(CurrentHeat, 0, GetMaxHeat());
		SetHeat(NewHeatValue);
	}
}

void UHeatAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	
}

void UHeatAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	if (Attribute == GetHeatAttribute())
	{
		OnHeatChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetMaxHeatAttribute())
	{
		OnMaxHeatChanged.Broadcast(this, OldValue, NewValue);
	}
}
