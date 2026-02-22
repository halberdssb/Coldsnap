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
	// run data
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 LevelReached;

	// options data - should move to game user options implementation
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	float Volume = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	float Sensitivity = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)

	// meta progression data
	int32 PlayerXP = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 PlayerLevel = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 XPToNextLevel = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	int32 PerkPoints = 0;

	// perk purhcase checks
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T1PerkOnePurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T1PerkTwoPurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T1PerkThreePurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T1PerkFourPurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T1PerkFivePurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T2PerkOnePurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T2PerkTwoPurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T2PerkThreePurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T2PerkFourPurchased = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	bool T2PerkFivePurchased = false;

	// array for holding all perk data
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	UPerkData* PerkData;
	
	UCOLDSNAPSaveGame();
};
