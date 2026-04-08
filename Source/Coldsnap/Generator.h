// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IHittable.h"
#include "GameFramework/Actor.h"
#include "Generator.generated.h"

/**
 * Generator interactable that helps activate drill on each layer when hit
 *
 * Jeff Stevenson
 * 10.24.25
 */
UCLASS()
class COLDSNAP_API AGenerator : public AActor, public IHittable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// IHittable implementation - currently implemented in blueprint
	void Hit_Implementation(bool stunEnemy, float damage, FVector knockbackForce) override;
};
