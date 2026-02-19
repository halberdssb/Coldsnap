// Copyright 2025 Icebreak Studios. All rights reserved.


#include "HittableCrate.h"

// Sets default values
AHittableCrate::AHittableCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void AHittableCrate::BeginPlay()
{
	Super::BeginPlay();
}

void AHittableCrate::Hit_Implementation(float damage, FVector knockbackForce)
{
	return;
}

void AHittableCrate::ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce)
{
	// Applies physics knockback force to the object
	Mesh->SetAllPhysicsLinearVelocity(FVector(0, 0, 0));
	Mesh->AddImpulse(knockbackDirection * knockbackForce);
}

