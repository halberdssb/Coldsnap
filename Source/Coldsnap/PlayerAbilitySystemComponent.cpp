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
	return AppliedGameplayEffects;
}

void UPlayerAbilitySystemComponent::AddGameplayEffectToAppliedEffectsArray(UAbilitySystemComponent* InASC, const FGameplayEffectSpec& InEffectSpec,
                                                                           FActiveGameplayEffectHandle InEffectHandle)
{
	AppliedGameplayEffects.Add(InEffectSpec);
}
