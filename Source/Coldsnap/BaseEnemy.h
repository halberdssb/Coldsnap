// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IHittable.h"
#include "IKnockbackable.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "BaseEnemy.generated.h"

UCLASS()
class COLDSNAP_API ABaseEnemy : public ACharacter, public IHittable, public IKnockbackable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Hit_Implementation() override;
	void ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce) override;
};
