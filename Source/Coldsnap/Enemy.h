// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthAttributeSet.h"
#include "IHittable.h"
#include "IKnockbackable.h"
#include "Upgrade.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Enemy.generated.h"

/**
 * Base enemy class that implements hittable and knockbackable interfaces
 *
 * Jeff Stevenson
 * 10.24.25
 */

UCLASS()
class COLDSNAP_API AEnemy : public ACharacter, public IHittable, public IKnockbackable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// GAS properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UHealthAttributeSet> HealthSet;
	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Hittable/Knockbackable interface implementation
	void Hit_Implementation(float damage, FVector knockbackForce) override;
	void ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce) override;

	// Handles logic to drop upgrades on death -
	// currently drops on hit becasue death not implemented yet
	UFUNCTION(BlueprintImplementableEvent, Category = Drops)
	void DropItemsOnDeath();
};
