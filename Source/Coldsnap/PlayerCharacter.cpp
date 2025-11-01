// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "AttackHitboxManager.h"
#include "HealthAttributeSet.h"
#include "HeatAttributeSet.h"
#include "PlayerMovementAttributeSet.h"
#include "PlayerAbilitySystemComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "GameFramework/CharacterMovementComponent.h"

/*
 * Default player class for Coldsnap
 *
 * Jeff Stevenson
 * 10.24.25
 */

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// add GAS attributes and ability system component
	PlayerAbilitySystemComp = CreateDefaultSubobject<UPlayerAbilitySystemComponent>(TEXT("PlayerAbilitySystemComponent"));
	CharacterMovementComp = ACharacter::GetCharacterMovement();
	HealthSet = CreateDefaultSubobject<UHealthAttributeSet>(TEXT("HealthAttributeSet"));
	MovementSet = CreateDefaultSubobject<UPlayerMovementAttributeSet>(TEXT("MovementAttributeSet"));
	HeatSet = CreateDefaultSubobject<UHeatAttributeSet>(TEXT("HeatAttributeSet"));
	PlayerAbilitySystemComp->AddAttributeSetSubobject<UHealthAttributeSet>(HealthSet);
	PlayerAbilitySystemComp->AddAttributeSetSubobject<UPlayerMovementAttributeSet>(MovementSet);

	// Add hitbox manager component
	AttackHitboxManager = CreateDefaultSubobject<UAttackHitboxManager>(TEXT("AttackHitboxManager"));
	
	// Set team ID to 2 - make enemies view player as separate team
	SetGenericTeamId(FGenericTeamId(2));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	PlayerAbilitySystemComp->InitAbilityActorInfo(this, this);
	CharacterMovementComp->MaxWalkSpeed = 600;

	SubscribeToAttributeChangeEvents();
}

void APlayerCharacter::SubscribeToAttributeChangeEvents()
{
	// Bind character movement walk speed to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetWalkSpeedAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateWalkSpeed);
	// Bind character movement max acceleration speed to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetMaxAccelerationAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateMaxAcceleration);
	// Bind character movement ground friction to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetGroundFrictionAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateGroundFriction);
	// Bind character movement falling friction to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetFallingLateralFrictionAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateFallingLateralFriction);
	// Bind character movement walking deceleration to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetWalkingDecelerationAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateWalkingDeceleration);
	// Bind character movement falling deceleration to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetFallingDecelerationAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateFallingDeceleration);
	// Bind character movement air control to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetAirControlAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateAirControl);
	// Bind character movement air boost to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetAirBoostMultiplierAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateAirBoostMultiplier);
	// Bind character movement dash speed to GAS attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetDashForceAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateDashForce);
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
	// Bind character movement gravity scale to GAS Attribute
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(MovementSet->GetGravityScaleAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateGravityScale);
	// Bind event to heat meter changed
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(HeatSet->GetHeatAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateHeat);
	// Bind event to max heat meter changed
	PlayerAbilitySystemComp->GetGameplayAttributeValueChangeDelegate(HeatSet->GetMaxHeatAttribute())
		.AddUObject(this, &APlayerCharacter::UpdateMaxHeat);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Handles GAS replication
void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Retrusn Gameplay Ability System
UAbilitySystemComponent* APlayerCharacter::GetAbilitySystemComponent() const
{
	return PlayerAbilitySystemComp;
}

// Sets player team ID to specific value
void APlayerCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	if (TeamID  != NewTeamID)
	{
		TeamID  = NewTeamID;
	}
}

// On Attribute Changed functions for GAS attributes:

void APlayerCharacter::UpdateWalkSpeed(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->MaxWalkSpeed = Data.NewValue;
}

void APlayerCharacter::UpdateMaxAcceleration(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->MaxAcceleration = Data.NewValue;
}

void APlayerCharacter::UpdateGroundFriction(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->GroundFriction = Data.NewValue;
}

void APlayerCharacter::UpdateFallingLateralFriction(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->FallingLateralFriction = Data.NewValue;
}

void APlayerCharacter::UpdateWalkingDeceleration(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->BrakingDecelerationWalking = Data.NewValue;
}

void APlayerCharacter::UpdateFallingDeceleration(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->BrakingDecelerationFalling = Data.NewValue;
}

void APlayerCharacter::UpdateAirControl(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->AirControl = Data.NewValue;
}

void APlayerCharacter::UpdateAirBoostMultiplier(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->AirControlBoostMultiplier = Data.NewValue;
}

void APlayerCharacter::UpdateDashForce(const FOnAttributeChangeData& Data)
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

void APlayerCharacter::UpdateHorizontalKnockbackMultiplier(const FOnAttributeChangeData& Data)
{
	horizontalKnockbackMultiplier = Data.NewValue;
}

void APlayerCharacter::UpdateTotalKnockbackMultiplier(const FOnAttributeChangeData& Data)
{
	totalKnockbackMultiplier = Data.NewValue;
}

void APlayerCharacter::UpdateDamageMultiplier(const FOnAttributeChangeData& Data)
{
	damageMultiplier = Data.NewValue;
}

void APlayerCharacter::UpdateHeat(const FOnAttributeChangeData& Data)
{
	// not implemented yet
}

void APlayerCharacter::UpdateMaxHeat(const FOnAttributeChangeData& Data)
{
	// not implemented yet
}

void APlayerCharacter::UpdateHeatGainMultiplier(const FOnAttributeChangeData& Data)
{
	// not implemented yet
}

void APlayerCharacter::UpdateGravityScale(const FOnAttributeChangeData& Data)
{
	CharacterMovementComp->GravityScale = Data.NewValue;
}


