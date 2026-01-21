// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAbilitySystemComponent.h"

/*
 * Custom Player Ability System Component
 *
 * Jeff Stevenson
 * 10.24.25
 */

UPlayerAbilitySystemComponent::UPlayerAbilitySystemComponent()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UPlayerAbilitySystemComponent::AddGameplayEffectToAppliedEffectsArray);
}

TArray<FGameplayEffectSpec> UPlayerAbilitySystemComponent::GetAllAppliedGameplayEffectSpecs()
{
	return AppliedUpgradeEffects;
}

void UPlayerAbilitySystemComponent::AddGameplayEffectToAppliedEffectsArray(UAbilitySystemComponent* InASC, const FGameplayEffectSpec& InEffectSpec,
                                                                           FActiveGameplayEffectHandle InEffectHandle)
{
	// check if the effect is an upgrade effect and add to list of applied upgrades if so
	FGameplayTagContainer TagContainer;
	InEffectSpec.GetAllGrantedTags(TagContainer);
	
	if (TagContainer.HasTag(FGameplayTag::RequestGameplayTag(FName("Upgrade"))))
	{
		AppliedUpgradeEffects.Add(InEffectSpec);
	}
}
