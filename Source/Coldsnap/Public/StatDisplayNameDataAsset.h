// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataAsset.h"
#include "StatDisplayNameDataAsset.generated.h"

/**
 * Holds display names of all stats to be displayed in inventory stats screen
 *
 * Jeff Stevenson
 * 4.12.26
 */

// Struct that holds info for displaying a stat in UI
USTRUCT(BlueprintType)
struct FStatDisplayInfo
{
public:
	GENERATED_BODY()

	// The name of the attribute that will be shown on the stats screen
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString DisplayName;

	// Modifier of the actual attribute to what is shown on stats screen - default is 1 (unchanged)
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ValueDisplayModifier = 1;
};

UCLASS(BlueprintType)
class COLDSNAP_API UStatDisplayNameDataAsset : public UDataAsset
{
public:
	GENERATED_BODY()

	// returns display info for a given attribute
	UFUNCTION(BlueprintCallable)
	FStatDisplayInfo GetAttributeDisplayInfo(FGameplayAttribute AttributeKey);

	// converts all attribute keys into an array and returns them
	UFUNCTION(BlueprintCallable)
	TArray<FGameplayAttribute> GetAttributeList();
	
private:
	// Map of attributes to given display info
	UPROPERTY(EditAnywhere)
	TMap<FGameplayAttribute, FStatDisplayInfo> DisplayNameMapping;

};
