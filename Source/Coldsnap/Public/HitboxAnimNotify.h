// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "HitboxAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class COLDSNAP_API UHitboxAnimNotify : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HitboxAnimNotify")
	float ElapsedNotifyTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HitboxAnimNotify")
	float AnimationFrameRate = 60;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HitboxAnimNotify")
	float AttackDuration;
	
	UFUNCTION(BlueprintCallable, Category = "HitboxAnimNotify")
	void UpdateElapsedNotifyTime(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "HitboxAnimNotify")
	void ResetElapsedNotifyTime();

	UFUNCTION(BlueprintCallable, Category = "HitboxAnimNotify")
	void SetAttackDuration(float Duration);
};
