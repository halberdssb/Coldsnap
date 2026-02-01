// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "UpgradeGameplayEffect.generated.h"

/**
 * Handles an individual attach point/consume effect for a given upgrade
 *
 * Jeff Stevenson
 * 10.24.25
 */

UCLASS()
class COLDSNAP_API UUpgradeGameplayEffect : public UGameplayEffect
{
	GENERATED_BODY()

public:
	// Tooltip field to be edited in inspector field in blueprints - displayed by equipment widget to describe effect
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(MultiLine=true))
	FString tooltip;

	UUpgradeGameplayEffect(const FObjectInitializer& ObjectInitializer);

private:
};
