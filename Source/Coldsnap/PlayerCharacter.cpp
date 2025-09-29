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
	CharacterMovementComp = ACharacter::GetCharacterMovement();
	HealthSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("HealthAttributeSet"));
	MovementSet = CreateDefaultSubobject<UMovementAttributeSet>(TEXT("MovementAttributeSet"));
	PlayerAbilitySystemComp->AddAttributeSetSubobject<UHealthAttributeSet>(HealthSet);
	PlayerAbilitySystemComp->AddAttributeSetSubobject<UMovementAttributeSet>(MovementSet);
	
	// Set team ID to 2 - enemy to enemies
	SetGenericTeamId(FGenericTeamId(2));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	PlayerAbilitySystemComp->InitAbilityActorInfo(this, this);
	CharacterMovementComp->MaxWalkSpeed = 600;

	// Bind character movement walk speed to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetGroundSpeedAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateWalkSpeed);
	// Bind character movement dash speed to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetDashForceAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateDashDuration);
	// Bind character movement attack speed to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetAttackSpeedAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateAttackSpeed);
	// Bind character movement jump out of dash value to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetDashJumpValueAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateAllowJumpDuringDash);
	// Bind character movement jump force to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetJumpForceAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateJumpForce);
	// Bind character movement vertical knockback multiplier to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetVerticalKnockbackMultiplierAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateVerticalKnockbackMultiplier);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
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

void APlayerCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	if (TeamID  != NewTeamID)
	{
		TeamID  = NewTeamID;
	}
}

void APlayerCharacter::UpdateWalkSpeed(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->MaxWalkSpeed = Data.NewValue;
}

void APlayerCharacter::UpdateDashDuration(const FOnAttributeChangeData& Data)
{
	dashForce = baseDashForce * Data.NewValue;
}

void APlayerCharacter::UpdateAttackSpeed(const FOnAttributeChangeData& Data)
{
	attackSpeed = Data.NewValue;
}

void APlayerCharacter::UpdateAllowJumpDuringDash(const FOnAttributeChangeData& Data)
{
	allowDashDuringJump = Data.NewValue > 0;
}

void APlayerCharacter::UpdateJumpForce(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->JumpZVelocity = Data.NewValue;
}

void APlayerCharacter::UpdateVerticalKnockbackMultiplier(const FOnAttributeChangeData& Data)
{
	verticalKnockbackMultiplier = Data.NewValue;
}


