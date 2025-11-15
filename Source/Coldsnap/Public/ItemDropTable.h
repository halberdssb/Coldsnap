// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDropTable.generated.h"

/**
 * Data for handling drops of items from enemies/objects
 */

USTRUCT()
struct FItemDropData
{
	GENERATED_BODY()

	// item pickup to be dropped
	UPROPERTY(EditAnywhere, Category = "Item Drops")
	TSubclassOf<AActor> ItemPickup;

	// weight for the item to drop
	UPROPERTY(EditAnywhere, Category = "Item Drops")
	int32 DropWeight;

	// layered drop weight - drop weight + weights of all previous items in table
	int32 LayeredDropWeight;
};

UCLASS()
class COLDSNAP_API UItemDropTable : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, Category = "Item Drops")
	TArray<FItemDropData> ItemDropTable;

	UFUNCTION(BlueprintCallable, Category = "Item Drops")
	TSubclassOf<AActor> CalculateDroppedItem();

	void CalculateLayeredDropWeights();

#if WITH_EDITOR
	// handles calculating overall weight total
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	int32 TotalWeight;
};
