// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Coldsnap/IHittable.h"
#include "Coldsnap/IKnockbackable.h"
#include "GameFramework/Actor.h"
#include "HittableCrate.generated.h"

/*
 * Crate object that receives attack knockback & applies player juggle physics like enemies for movement/traversal
 *
 * Jeff Stevenson
 * 2.15.26
 */

UCLASS()
class COLDSNAP_API AHittableCrate : public APawn, public IHittable, public IKnockbackable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHittableCrate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;
	
	void Hit_Implementation(bool stunEnemy, float damage, FVector knockbackForce) override;
	void ApplyKnockback_Implementation(FVector knockbackDirection, float knockbackForce) override;
	
};
