// Copyright 2025 Icebreak Studios. All rights reserved.


#include "ItemDropTable.h"

TSubclassOf<AActor> UItemDropTable::CalculateDroppedItem()
{
	// get random drop value
	int32 RandomDropValue = FMath::RandRange(0, TotalWeight);

	TSubclassOf<AActor> DroppedItem = AActor::StaticClass();
	
	// iterate through drop table - lowest drop chance is dropped item
	for (FItemDropData ItemData : ItemDropTable)
	{
		if (RandomDropValue <= ItemData.LayeredDropWeight)
		{
			DroppedItem = ItemData.ItemPickup;
			return DroppedItem;
		}
	}
	
	return nullptr;
}

void UItemDropTable::CalculateLayeredDropWeights()
{
	TotalWeight = 0;
	for (int i = 0; i < ItemDropTable.Num(); i++)
	{
		ItemDropTable[i].LayeredDropWeight = ItemDropTable[i].DropWeight + TotalWeight;
		TotalWeight += ItemDropTable[i].DropWeight;
	}
}

#if WITH_EDITOR
void UItemDropTable::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	// calculate total weight & layered drop weights for each item
	CalculateLayeredDropWeights();

}
#endif

