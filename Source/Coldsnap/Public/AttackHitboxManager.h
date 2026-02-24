// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "FHitboxData.h"
#include "Components/ActorComponent.h"
#include "AttackHitboxManager.generated.h"

/*
 * Handles creation and data for player attack hitboxes
 *
 * Jeff Stevenson
 * 11.15.25
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHitboxHitActorsDelegate, const TArray<AActor*>&, HitActors, const FHitboxData, HitboxData);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLDSNAP_API UAttackHitboxManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackHitboxManager();

	// Event that is fired when one or more objects are hit by a hitbox
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FHitboxHitActorsDelegate HitboxHitActorsDelegate;

	// array of actors already hit by current hitbox
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> IgnoredActors;

	// Creates a capsule hitbox
	UFUNCTION(BlueprintCallable, Category = "Attack Hitbox Manager")
	TArray<AActor*> CreateAttackHitbox(FHitboxData InHitboxData);

	// Resets list of ignored actors (except for self)
	UFUNCTION(BlueprintCallable, Category = "Attack Hitbox Manager")
	void ResetIgnoredHitActors();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// filter for hittable classes - should only be IHittable actors - CURRENTLY UNUSED
	UClass* classHitFilter;

	// method for applying damage effects, heat gain effects, other effects on hit - currently implemented in blueprints
	void HitActors(TArray<AActor*> HitActors);
};
