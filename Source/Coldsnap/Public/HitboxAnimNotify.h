// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "HitboxAnimNotify.generated.h"

/**
 * Custom anim notify that spawns a single hitbox with hitbox data for the length of the notify
 *
 * Jeff Stevenson
 * 11.26.25
 */
UCLASS()
class COLDSNAP_API UHitboxAnimNotify : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	// time elapsed by notify - currently unused
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HitboxAnimNotify")
	float ElapsedNotifyTime;

	// total duration of attack active frames
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HitboxAnimNotify")
	float AttackDuration;
	
	UFUNCTION(BlueprintCallable, Category = "HitboxAnimNotify")
	void UpdateElapsedNotifyTime(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "HitboxAnimNotify")
	void ResetElapsedNotifyTime();

	UFUNCTION(BlueprintCallable, Category = "HitboxAnimNotify")
	void SetAttackDuration(float Duration);
};
