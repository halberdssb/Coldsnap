// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDropTable.generated.h"

/**
 * Data for handling drops of items from enemies/objects
 *
 * Jeff Stevenson
 * 11.21.26
 */

// holds data for a single droppable item in table
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

	// array of all possible items to drop in drop table
	UPROPERTY(EditAnywhere, Category = "Item Drops")
	TArray<FItemDropData> ItemDropTable;

	// rolls random chance for if an item is dropped and if so, which one
	UFUNCTION(BlueprintCallable, Category = "Item Drops")
	TSubclassOf<AActor> CalculateDroppedItem();

	// offsets drop weights of all items in table to not overlap for easy drop chance logic
	void CalculateLayeredDropWeights();

#if WITH_EDITOR
	// handles calculating overall weight total
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	// total weight of all items after offset
	int32 TotalWeight;
};
