// Copyright 2025 Icebreak Studios. All rights reserved.


#include "HitboxAnimNotify.h"

void UHitboxAnimNotify::UpdateElapsedNotifyTime(float DeltaTime)
{
	ElapsedNotifyTime += DeltaTime;
}

void UHitboxAnimNotify::ResetElapsedNotifyTime()
{
	ElapsedNotifyTime = 0;
}

void UHitboxAnimNotify::SetAttackDuration(float Duration)
{
	AttackDuration = Duration;
}
