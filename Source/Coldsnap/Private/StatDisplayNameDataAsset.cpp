// Copyright 2025 Icebreak Studios. All rights reserved.


#include "StatDisplayNameDataAsset.h"

// returns display info for a given attribute
FStatDisplayInfo UStatDisplayNameDataAsset::GetAttributeDisplayInfo(FGameplayAttribute AttributeKey)
{
	return *DisplayNameMapping.Find(AttributeKey);
}

// converts all attribute keys into an array and returns them
TArray<FGameplayAttribute> UStatDisplayNameDataAsset::GetAttributeList()
{
	TArray<FGameplayAttribute> AttributeList;
	DisplayNameMapping.GenerateKeyArray(AttributeList);
	return AttributeList;
}
