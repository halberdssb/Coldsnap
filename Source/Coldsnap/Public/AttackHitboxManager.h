// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "FHitboxData.h"
#include "Components/ActorComponent.h"
#include "AttackHitboxManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHitboxHitActorsDelegate, const TArray<AActor*>&, HitActors, const FHitboxData, HitboxData);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLDSNAP_API UAttackHitboxManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackHitboxManager();

	// Event that is fired when one or more objects are hit by a hitbox
	UPROPERTY(BlueprintAssignable)
	FHitboxHitActorsDelegate HitboxHitActorsDelegate;
	
	// filter for hittable classes - should only be IHittable actors
	UClass* classHitFilter;

	// Creates a capsule hitbox
	UFUNCTION(BlueprintCallable, Category = "Attack Hitbox Manager")
	TArray<AActor*> CreateAttackHitbox(FHitboxData InHitboxData);

	void HitActors(TArray<AActor*> HitActors);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
