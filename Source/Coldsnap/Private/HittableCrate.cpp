// Copyright 2025 Icebreak Studios. All rights reserved.


#include "HittableCrate.h"

AHittableCrate::AHittableCrate()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void AHittableCrate::BeginPlay()
{
	Super::BeginPlay();
}

void AHittableCrate::Hit_Implementation(bool stunEnemy, float damage, FVector knockbackForce)
{
	// empty - implemented in blueprints
	return;
}

void AHittableCrate::ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce)
{
	// Applies physics knockback force to the object
	Mesh->SetAllPhysicsLinearVelocity(FVector(0, 0, 0));
	Mesh->AddImpulse(knockbackDirection * knockbackForce);
}

