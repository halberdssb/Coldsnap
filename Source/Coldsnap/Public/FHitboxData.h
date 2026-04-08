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
		const FVector& KnockbackDirection, float KnockbackForce, float Damage, bool ShouldStun, float StunTime, FVector PlayerLaunchForce)
		: PositionOffset(PositionOffset),
		  Height(Height),
		  Radius(Radius),
		  Rotation(Rotation),
		  KnockbackDirection(KnockbackDirection),
		  KnockbackForce(KnockbackForce),
		  Damage(Damage),
		  ShouldStun(ShouldStun),
		  StunTime(StunTime),
		  PlayerLaunchForce(PlayerLaunchForce)
	{}

	~FHitboxData();

	// position of hitbox relative to player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FVector PositionOffset;
	// height of hitbox capsule collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float Height;
	// radius of hitbox capsule collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float Radius;
	// rotation of hitbox capsule collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FRotator Rotation;

	// direction of hitbox knockback - should be/will be used as normalized value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FVector KnockbackDirection;
	// magnitude of knockback force
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float KnockbackForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float Damage;
	// should this attack stun enemies?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	bool ShouldStun;
	// time enemies are stunned for by attack
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	float StunTime;
	// force applied to player when hit - used for aerial juggle suspension
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitboxData")
	FVector PlayerLaunchForce;
};
