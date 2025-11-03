// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeAttackGameplayAbility.h"

#include "Enemy.h"
#include "FHitboxData.h"
#include "IHittable.h"
#include "IKnockbackable.h"
#include "Kismet/KismetSystemLibrary.h"

UMeleeAttackGameplayAbility::UMeleeAttackGameplayAbility()
{
	// only hit Hittable objects
	classHitFilter = IHittable::UClassType::StaticClass();
}

// Creates a spherecast hitbox
TArray<AActor*> UMeleeAttackGameplayAbility::CreateMeleeHitbox(FHitboxData InHitboxData)
{
	// Object types to trace for - only pawns
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes = {UEngineTypes::ConvertToObjectType(ECC_Pawn)};
	
	// Ignore self
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(GetAvatarActorFromActorInfo());
	
	TArray<AActor*> overlappingActors;

	// Do overlap sphere cast
	UKismetSystemLibrary::CapsuleOverlapActorsWithOrientation(GetWorld(), InHitboxData.PositionOffset, InHitboxData.Radius, InHitboxData.Height / 2,
	InHitboxData.Rotation, objectTypes, classHitFilter, actorsToIgnore, overlappingActors);
	
	// Return if no actors found
	if (overlappingActors.Num() < 0) return TArray<AActor*>();

	return overlappingActors;
}
