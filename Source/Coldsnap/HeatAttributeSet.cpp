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
	InitHeatDrainValue(BaseHeatDrainValue);
	InitHeatDrainMultiplier(BaseHeatDrainMultiplier);
}

void UHeatAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// heat changed
	if (Data.EvaluatedData.Attribute == GetHeatAttribute())
	{		
		float CurrentHeat = GetHeat();

		// multiply by heat gain mult if gain was positive
		if (Data.EvaluatedData.Magnitude > 0)
		{
			CurrentHeat *= GetHeatGainMultiplier();
		}

		// clamp new heat
		float NewHeatValue = FMath::Clamp(CurrentHeat, 0, GetMaxHeat());
		SetHeat(NewHeatValue);

		// handle application of has heat tag if target's heat is above 0
		FGameplayTag HasHeatTag = FGameplayTag::RequestGameplayTag(FName("Heat.HasHeat"));
		if (NewHeatValue > 0 && !Data.Target.HasMatchingGameplayTag(HasHeatTag))
		{
			FGameplayTagContainer HeatTagContainer;
			HeatTagContainer.AddTag(HasHeatTag);
			Data.Target.AddLooseGameplayTags(HeatTagContainer);
		}
		else if (NewHeatValue <= 0)
		{
			Data.Target.RemoveLooseGameplayTag(HasHeatTag);
		}
	}
}

void UHeatAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	
}

void UHeatAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	// heat changed delegate
	if (Attribute == GetHeatAttribute())
	{
		OnHeatChanged.Broadcast(this, OldValue, NewValue);
	}
	// max heat changed delegate
	else if (Attribute == GetMaxHeatAttribute())
	{
		OnMaxHeatChanged.Broadcast(this, OldValue, NewValue);
	}
}
