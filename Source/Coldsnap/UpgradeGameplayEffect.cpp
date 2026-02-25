// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeGameplayEffect.h"
#include "GameplayEffectComponents/TargetTagsGameplayEffectComponent.h"

/**
 * Handles an individual attach point/consume effect for a given upgrade
 *
 * Jeff Stevenson
 * 10.24.25
 */

UUpgradeGameplayEffect::UUpgradeGameplayEffect(const FObjectInitializer& ObjectInitializer)
{
	DurationPolicy = EGameplayEffectDurationType::Infinite;
	
	// add the upgrade tag to the granted tags list
	UTargetTagsGameplayEffectComponent* TargetTags = ObjectInitializer.CreateDefaultSubobject<UTargetTagsGameplayEffectComponent>(this, TEXT("TargetTagsGameplayEffectComponent"));

	// ensure all upgrade effects have upgrade tag for persistence tracking
	FInheritedTagContainer TagContainer;
	TagContainer.Added.AddTag(FGameplayTag::RequestGameplayTag(FName("Upgrade")));

	TargetTags->SetAndApplyTargetTagChanges(TagContainer);
	GEComponents.Add(TargetTags);
}
