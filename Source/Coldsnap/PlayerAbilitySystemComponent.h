// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayAbilityInputData.h"
#include "PlayerAbilitySystemComponent.generated.h"

/*
 * Custom Player Ability System Component
 *
 * Jeff Stevenson
 * 10.24.25
 */
UCLASS()
class COLDSNAP_API UPlayerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UPlayerAbilitySystemComponent();

	UPROPERTY(EditAnywhere)
	UGameplayAbilityInputData* AbilityInputMappings;

	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	TArray<FGameplayAbilitySpecHandle> MappedAbilitySpecHandles;
};
