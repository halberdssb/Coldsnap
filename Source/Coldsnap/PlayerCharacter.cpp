// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.h"
#include "MovementAttributeSet.h"
#include "PlayerAbilitySystemComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerAbilitySystemComp = CreateDefaultSubobject<UPlayerAbilitySystemComponent>(TEXT("PlayerAbilitySystemComponent"));
	HealthSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("HealthAttributeSet"));
	MovementSet = CreateDefaultSubobject<UMovementAttributeSet>(TEXT("MovementAttributeSet"));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	PlayerAbilitySystemComp->InitAbilityActorInfo(this, this);
	CharacterMovementComp = GetOwner()->FindComponentByClass<UCharacterMovementComponent>();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* APlayerCharacter::GetAbilitySystemComponent() const
{
	return PlayerAbilitySystemComp;
}

