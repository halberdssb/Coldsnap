// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbilityInputData.generated.h"

/**
 * Data asset for binding enhanced input actions to gameplay abilities
 *
 * Jeff Stevenson
 * 11.1.25
 */

class UInputAction;

USTRUCT()
struct FGameplayAbilityInputMapping
{
	GENERATED_BODY()

	// ability to be mapped to certain input
	UPROPERTY(EditAnywhere, Category = "Gameplay Ability Input Mapping")
	TSubclassOf<UGameplayAbility> GameplayAbility;

	// enhanced input action that ability will map to
	UPROPERTY(EditAnywhere, Category = "Gameplay Ability Input Mapping")
	TObjectPtr<UInputAction> InputMapping;

	// ID for the input mapping
	UPROPERTY(VisibleAnywhere, Category = "Gameplay Ability Input Mapping")
	int32 InputID;

	// equals and not equals operator implementation
	bool operator==(const FGameplayAbilityInputMapping& Other) const
	{
		return GameplayAbility == Other.GameplayAbility && InputID == Other.InputID;
	}

	bool operator!=(const FGameplayAbilityInputMapping& Other) const
	{
		return !operator==(Other);
	}
	
	// checks if ability and mapping are both filled for the mapping data
	bool IsValid() const
	{
		return GameplayAbility && InputMapping;
	}

	// Hash type pairing for TSet pairing
	friend uint32 GetTypeHash(const FGameplayAbilityInputMapping& Item)
	{
		return HashCombine(GetTypeHash(Item.GameplayAbility), GetTypeHash(Item.InputMapping));
	}
	
	FGameplayAbilityInputMapping()
		: InputID(INDEX_NONE)
	{}
};

UCLASS()
class COLDSNAP_API UGameplayAbilityInputData : public UDataAsset
{
	GENERATED_BODY()

public:
	UGameplayAbilityInputData(const FObjectInitializer& ObjectInitializer);
	
	// list of ability-input action mappings
	UPROPERTY(EditAnywhere, Category = "Gameplay Ability Input Mapping")
	TSet<FGameplayAbilityInputMapping> AbilityInputMappings;

	// returns the input mappings
	const TSet<FGameplayAbilityInputMapping> GetInputMappings();

#if WITH_EDITOR
	// handles updating list and IDs with editor values
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
