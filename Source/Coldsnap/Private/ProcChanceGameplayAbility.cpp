// Copyright 2025 Icebreak Studios. All rights reserved.


#include "ProcChanceGameplayAbility.h"
#include "FOnHitInfo.h"
#include "PlayerMovementAttributeSet.h"

bool UProcChanceGameplayAbility::IsAbilityProcced()
{
	UPlayerMovementAttributeSet* AttrSet = GetAbilitySystemComponent()->GetSet<UPlayerMovementAttributeSet>();
	float LifeStealChance = AttrSet ? AttrSet->GetLifeStealChance() : 0.0f;

	// Generate a random integer between 1 and 100
	int32 RandomRoll = FMath::RandRange(1, 100);

	// Compare random roll to life steal chance (as a percentage)
	return RandomRoll <= LifeStealChance;
}
