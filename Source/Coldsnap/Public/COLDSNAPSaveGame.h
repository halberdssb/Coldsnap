// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PerkData.h"
#include "COLDSNAPSaveGame.generated.h"

/**
 * Handles save data for metaprogression & settings in game
 *
 * Jeff Stevenson
 * 1.17.26
 */

UCLASS()
class COLDSNAP_API UCOLDSNAPSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 LevelReached;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	float Volume = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	float Sensitivity = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 PlayerXP = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 PlayerLevel = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 XPToNextLevel = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 PerkPoints = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool perkOnePurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool perkTwoPurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool perkThreePurchased = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	UPerkData* PerkData;
	
	UCOLDSNAPSaveGame();
};
