// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeAttackGameplayAbility.h"

#include "BaseEnemy.h"
#include "IHittable.h"
#include "IKnockbackable.h"
#include "Kismet/KismetSystemLibrary.h"

UMeleeAttackGameplayAbility::UMeleeAttackGameplayAbility()
{
	classHitFilter = IHittable::UClassType::StaticClass();
}

TArray<AActor*> UMeleeAttackGameplayAbility::CreateMeleeHitbox(FVector position, float radius, FVector knockbackDirection, float knockbackForce, uint8 framesActive, bool drawDebugSphere)
{
	// Draw debug sphere to show hitbox
	if (drawDebugSphere)
	{
		DrawDebugSphere(GetWorld(), position, radius, 20, FColor::Red, true);
	}

	// Object types to trace for - only pawns
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes = {UEngineTypes::ConvertToObjectType(ECC_Pawn)};
	
	// Ignore self
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(GetAvatarActorFromActorInfo());
	
	TArray<AActor*> overlappingActors;

	// Do overlap sphere cast
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), position, radius, objectTypes, nullptr, actorsToIgnore, overlappingActors);

	// Return if no actors found
	if (overlappingActors.Num() < 0) return TArray<AActor*>();

	/*for (int i = 0; i < overlappingActors.Num(); i++)
	{
		// check for hittable actors
		if (!overlappingActors[i]->Implements<UHittable>())
		{
			overlappingActors.RemoveAt(i--);
		}
		else
		{
			IHittable* hittable = Cast<IHittable>(overlappingActors[i]);
			hittable->Hit();
		}

		// check for knockbackable actors
		if (!overlappingActors[i]->Implements<UKnockbackable>())
		{
			overlappingActors.RemoveAt(i--);
		}
		else
		{
			IHittable* hittable = Cast<IHittable>(overlappingActors[i]);
			hittable->Hit();
		}
	}*/

	return overlappingActors;
}
