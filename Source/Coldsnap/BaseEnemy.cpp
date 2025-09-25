// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("Health"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEnemy::Hit_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy hit!"));
}

void ABaseEnemy::ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce)
{
	UCapsuleComponent* capsuleComponent = GetCapsuleComponent();

	capsuleComponent->SetAllPhysicsLinearVelocity(FVector(0, 0, 0));
	capsuleComponent->AddImpulse(knockbackDirection * knockbackForce);
	UE_LOG(LogTemp, Warning, TEXT("PUSH"));
}



