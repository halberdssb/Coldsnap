// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeGameplayEffect.h"
#include "GameplayEffectComponents/TargetTagsGameplayEffectComponent.h"

/**
 * Handles an individual attach point/consume effect for a given upgrade
 *
 * Jeff Stevenson
 * 10.24.25
 */

UUpgradeGameplayEffect::UUpgradeGameplayEffect()
{
	// add the upgrade tag to the granted tags list
	UTargetTagsGameplayEffectComponent* TargetTags = CreateDefaultSubobject<UTargetTagsGameplayEffectComponent>(TEXT("Tags"));

	FInheritedTagContainer TagContainer;
	TagContainer.Added.AddTag(FGameplayTag::RequestGameplayTag(FName("Upgrade")));

	TargetTags->SetAndApplyTargetTagChanges(TagContainer);
}
