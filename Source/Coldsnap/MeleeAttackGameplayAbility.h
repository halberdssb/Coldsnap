// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IHittable.h"
#include "Abilities/GameplayAbility.h"
#include "MeleeAttackGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class COLDSNAP_API UMeleeAttackGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UMeleeAttackGameplayAbility();

	UClass* classHitFilter;
	
	UFUNCTION(BlueprintCallable, Category = "Melee")
	TArray<AActor*> CreateMeleeHitbox(FVector position, float radius, FVector knockbackDirection, float knockbackForce, uint8 framesActive, bool drawDebugSphere);
};
