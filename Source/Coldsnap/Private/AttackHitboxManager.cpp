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
	// Ignore self and child component actors
	IgnoredActors.Add(GetOwner());
	/*TArray<AActor*> ChildActorsOfSelf;
	GetOwner()->GetAllChildActors(ChildActorsOfSelf, true);
	for (AActor* ChildActor : ChildActorsOfSelf)
	{
		IgnoredActors.Add(ChildActor);
	}*/
}

TArray<AActor*> UAttackHitboxManager::CreateAttackHitbox(FHitboxData InHitboxData)
{
	// Object types to trace for - only pawns
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes = {UEngineTypes::ConvertToObjectType(ECC_Pawn)};
	
	TArray<AActor*> overlappingActors;

	// Do overlap sphere cast
	UKismetSystemLibrary::CapsuleOverlapActorsWithOrientation(GetWorld(), InHitboxData.PositionOffset, InHitboxData.Radius, InHitboxData.Height / 2,
	InHitboxData.Rotation, objectTypes, nullptr, IgnoredActors, overlappingActors);
	
	// Return if no actors found
	if (overlappingActors.Num() < 0) return TArray<AActor*>();

	// Remove any actors already hit by this attack - already hit actors is reset at start of each attack
	for (AActor* overlappingActor : overlappingActors)
	{
		if (!IgnoredActors.Contains(overlappingActor))
		{
			IgnoredActors.Add(overlappingActor);
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

void UAttackHitboxManager::ResetIgnoredHitActors()
{
	IgnoredActors.Empty();
	IgnoredActors.Add(GetOwner());
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

