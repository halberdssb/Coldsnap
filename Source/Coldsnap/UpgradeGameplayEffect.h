// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "UpgradeGameplayEffect.generated.h"

/**
 * 
 */
UCLASS()
class COLDSNAP_API UUpgradeGameplayEffect : public UGameplayEffect
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString tooltip;

	/*UFUNCTION(BlueprintCallable, Category = "Upgrade")
	FString GetTooltip() const { return tooltip; } */
};
