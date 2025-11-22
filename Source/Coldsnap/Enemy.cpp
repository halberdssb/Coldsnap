// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up GAS systems
	HealthSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("Health"));
	HealthSet->InitHealth(1);
	HealthSet->InitMaxHealth(1);
	HealthSet->InitDamage(1);
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->AddAttributeSetSubobject<UHealthAttributeSet>(HealthSet);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	DropTable->CalculateLayeredDropWeights();
	Super::BeginPlay();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// currently unimplemented - should apply damage to health attribute
void AEnemy::Hit_Implementation(float damage, FVector knockbackForce)
{
	
}

void AEnemy::ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce)
{
	// Applies physics knockback force to capsule component on enemy
	UCapsuleComponent* capsuleComponent = GetCapsuleComponent();

	capsuleComponent->SetAllPhysicsLinearVelocity(FVector(0, 0, 0));
	capsuleComponent->AddImpulse(knockbackDirection * knockbackForce);
}


