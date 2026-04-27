// Copyright 2025 Icebreak Studios. All rights reserved.


#include "ProcChanceGameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "FOnHitInfo.h"
#include "Coldsnap/PlayerMovementAttributeSet.h"

bool UProcChanceGameplayAbility::IsAbilityProcced()
{
	const UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponentFromActorInfo();
	if (!AbilitySystemComponent)
	{
		return false;
	}

	const float LifeStealChance = AbilitySystemComponent->GetNumericAttribute(
		UPlayerMovementAttributeSet::GetLifeStealChanceAttribute());

	const int32 RandomNumber = FMath::RandRange(1, 100);

	return RandomNumber <= LifeStealChance;
}
