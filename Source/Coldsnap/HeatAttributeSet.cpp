// Copyright 2025 Icebreak Studios. All rights reserved.


#include "HeatAttributeSet.h"

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
}

void UHeatAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHeatAttribute())
	{
		SetHeat(FMath::Clamp(NewValue, 0, GetMaxHeat()));
	}
	else if (Attribute == GetMaxHeatAttribute())
	{
		SetMaxHeat(FMath::Clamp(NewValue, 0, GetMaxHeat()));
	}
	
	Super::PreAttributeChange(Attribute, NewValue);
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
