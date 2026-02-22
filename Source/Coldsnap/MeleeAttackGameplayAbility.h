// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IHittable.h"
#include "Abilities/GameplayAbility.h"
#include "MeleeAttackGameplayAbility.generated.h"

/**
 * Base player attack ability - defines creation of hitboxes for damage & knockback interfaces
 */

UCLASS()
class COLDSNAP_API UMeleeAttackGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UMeleeAttackGameplayAbility();

	// attack animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack Animation")
	UAnimMontage* AttackAnimMontage;
	
	// filter for hittable classes - should only be IHittable actors
	UClass* classHitFilter;

	// Creates a spherecast hitbox for at a given location with damage and knockback valeus
	UFUNCTION(BlueprintCallable, Category = "Melee")
	TArray<AActor*> CreateMeleeHitbox(FHitboxData InHitboxData);
};
