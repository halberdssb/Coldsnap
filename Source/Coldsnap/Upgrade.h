// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpgradeGameplayEffect.h"
#include "GameplayEffect.h"
#include "Upgrade.generated.h"

/**
 * Interactable upgrade item with multiple effects to be chosen from
 *
 * Jeff Stevenson
 * 10.24.25
 */

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLDSNAP_API UUpgrade : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUpgrade();

	// Displayed upgrade name in upgrade UI in-game
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UpgradeName;

	// All possible selectable effects:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUpgradeGameplayEffect> armsGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUpgradeGameplayEffect> legsGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUpgradeGameplayEffect> torsoGameplayEffect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUpgradeGameplayEffect> fuelGameplayEffect;

protected:
	virtual void BeginPlay() override;
};
