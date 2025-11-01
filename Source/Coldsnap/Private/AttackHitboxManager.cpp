// Copyright 2025 Icebreak Studios. All rights reserved.


#include "AttackHitboxManager.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Actor.h"
#include "Coldsnap/IHittable.h"
#include "Kismet/KismetSystemLibrary.h"

UAttackHitboxManager::UAttackHitboxManager()
{
	classHitFilter = IHittable::UClassType::StaticClass();
}


void UAttackHitboxManager::BeginPlay()
{
	Super::BeginPlay();
	
}

TArray<AActor*> UAttackHitboxManager::CreateAttackHitbox(FHitboxData InHitboxData)
{
	// Object types to trace for - only pawns
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes = {UEngineTypes::ConvertToObjectType(ECC_Pawn)};
	
	// Ignore self
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(GetOwner());
	
	TArray<AActor*> overlappingActors;

	// Do overlap sphere cast
	UKismetSystemLibrary::CapsuleOverlapActorsWithOrientation(GetWorld(), InHitboxData.PositionOffset, InHitboxData.Radius, InHitboxData.Height / 2,
	InHitboxData.Rotation, objectTypes, nullptr, actorsToIgnore, overlappingActors);
	
	// Return if no actors found
	if (overlappingActors.Num() < 0) return TArray<AActor*>();

	// Remove any actors already hit by this attack - already hit actors is reset at start of each attack
	for (AActor* overlappingActor : overlappingActors)
	{
		if (!ActorsAlreadyHit.Contains(overlappingActor))
		{
			ActorsAlreadyHit.Add(overlappingActor);
		}
		else
		{
			overlappingActors.Remove(overlappingActor);
		}
	}
	// Fire hit actors delegate if any actors were hit
	HitboxHitActorsDelegate.Broadcast(overlappingActors, InHitboxData);
	return overlappingActors;
}

// method for applying damage effects, heat gain effects, other effects on hit - currently implemented in blueprints
void UAttackHitboxManager::HitActors(TArray<AActor*> HitActors)
{
	/*for (AActor* HitActor : HitActors)
	{
		UAbilitySystemComponent* AbilitySystemComponent = HitActor->FindComponentByClass<UAbilitySystemComponent>();

		// try deal damage
		if  (AbilitySystemComponent)
		{
			float level = 1;
			AbilitySystemComponent->ApplyGameplayEffectToTarget(AbilitySystemComponent, level, )
		}
	}*/
}

