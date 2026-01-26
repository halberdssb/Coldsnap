// Copyright 2025 Icebreak Studios. All rights reserved.


#include "FOnHitInfo.h"
#include "ProcChanceGameplayAbility.h"

bool UProcChanceGameplayAbility::IsAbilityProcced()
{
	float RandomSeed = (float)rand() / (float)RAND_MAX;

	return RandomSeed <= ProcChance;
}
