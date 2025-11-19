// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "FOnHitInfo.generated.h"

/**
 * Holds relevant data for on-hit effects on hit
 *
 * Jeff Stevenson
 * 11.17.25
 */

USTRUCT(BlueprintType)
struct FOnHitInfo
{
public:
	GENERATED_BODY()
	
	FOnHitInfo();

	FOnHitInfo(AActor* HitTarget, AActor* HitPerformer, FVector HitLocation, bool TargetKilled);

	~FOnHitInfo();

	// The actor that was hit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnHitInfo")
	AActor* HitTarget;
	// The actor that performed the hit/did the hitting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnHitInfo")
	AActor* HitPerformer;
	// The location of the hit target
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnHitInfo")
	FVector HitLocation;
	// Whether or not the target was killed by the hit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnHitInfo")
	bool TargetKilled;
};
