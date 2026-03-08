// Copyright 2025 Icebreak Studios. All rights reserved.


#include "PersistentUpgradeGameplayEffect.h"
#include "GameplayEffectComponents/TargetTagsGameplayEffectComponent.h"

UPersistentUpgradeGameplayEffect::UPersistentUpgradeGameplayEffect(const FObjectInitializer& ObjectInitializer)
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
