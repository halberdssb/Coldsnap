// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "NiagaraComponent.h"
#include "Components/AudioComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

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

	// spawn and vfx particles - don't activate on start
	SpawnVFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("SpawnVFX"));
	SpawnVFX->SetAutoActivate(false);
	HitVFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("HitVFX"));
	HitVFX->SetAutoActivate(false);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	// offset item drop weights to drop at correct odds on death
	DropTable->CalculateLayeredDropWeights();

	// handle vfx and model fade in delay
	HandleSpawnVisuals();
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// currently unimplemented - should apply damage to health attribute
void AEnemy::Hit_Implementation(bool stunEnemy, float damage, FVector knockbackForce)
{
	if (HitAudio)
	{
		HitAudio->Play();
	}
}

void AEnemy::ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce)
{
	// Applies physics knockback force to capsule component on enemy
	UCapsuleComponent* capsuleComponent = GetCapsuleComponent();

	capsuleComponent->SetAllPhysicsLinearVelocity(FVector(0, 0, 0));
	capsuleComponent->AddImpulse(knockbackDirection * knockbackForce);
}

void AEnemy::HandleSpawnVisuals()
{
	// enemy shouldn't be visible or move until particles are fully playing
	GetMesh()->SetVisibility(true);
	GetCharacterMovement()->Deactivate();
	
	// play spawn vfx and delay model to appear when hidden by vfx cloud

	// spawn particles at bottom of capsule collider (on ground)
	/*FVector ParticleLocation = GetCapsuleComponent()->GetComponentLocation();
	ParticleLocation.Z -= GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	SpawnVFX->SetWorldLocation(ParticleLocation);
	SpawnVFX->Activate(true);*/

	// enable mesh after delay to let particles flare up
	float delayTime = 0.5f;
	FTimerHandle ShowMeshTimerHandle;
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindUObject(this, &AEnemy::EnableMesh);
	GetWorld()->GetTimerManager().SetTimer(ShowMeshTimerHandle, TimerDelegate, delayTime, false);
}

void AEnemy::EnableMesh()
{
	GetMesh()->SetVisibility(true);
	GetCharacterMovement()->Activate();

	// disable particles - remove once moved to burst effect
	//SpawnVFX->Deactivate();
}


