// Copyright 2025 Icebreak Studios. All rights reserved.


#include "OnHitChanceEffect.h"

void UOnHitChanceEffect::RollOnHitChanceEffeect(FOnHitInfo HitInfo)
{
	float RandomSeed = (float)rand() / (float)RAND_MAX;

	if (ProcChance <= RandomSeed)
	{
		
	}
}
