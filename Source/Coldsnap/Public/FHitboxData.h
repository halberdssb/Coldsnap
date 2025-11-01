// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "FHitboxData.generated.h"

/**
 * Contains data for a hitbox
 *
 * Jeff Stevenson
 * 10.31.25
 */

USTRUCT(BlueprintType)
struct FHitboxData
{
public:
	GENERATED_BODY()
	
	FHitboxData();

	FHitboxData(const FVector& PositionOffset, float Height, float Radius, const FRotator& Rotation,
		const FVector& KnockbackDirection, float KnockbackForce, float Damage, float StunTime, FVector PlayerLaunchForce)
		: PositionOffset(PositionOffset),
		  Height(Height),
		  Radius(Radius),
		  Rotation(Rotation),
		  KnockbackDirection(KnockbackDirection),
		  KnockbackForce(KnockbackForce),
		  Damage(Damage),
		  StunTime(StunTime),
		  PlayerLaunchForce(PlayerLaunchForce)
	{}

	~FHitboxData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FVector PositionOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float Height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float Radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FRotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FVector KnockbackDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float KnockbackForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float StunTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FVector PlayerLaunchForce;
};
