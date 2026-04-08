// Copyright 2025 Icebreak Studios. All rights reserved.


#include "FHitboxData.h"

FHitboxData::FHitboxData()
{
	PositionOffset = FVector(0, 0, 0);
	Height = 1;
	Radius = 1;
	Rotation = FRotator(0, 0, 0);
	KnockbackDirection = FVector(0, 0, 0);
	KnockbackForce = 0; 
	Damage = 0;
	ShouldStun = false;
	StunTime = 0;
	PlayerLaunchForce = FVector(0, 0, 0);
}

FHitboxData::~FHitboxData()
{
}
