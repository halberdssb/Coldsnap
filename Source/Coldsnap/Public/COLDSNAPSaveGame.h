// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "COLDSNAPSaveGame.generated.h"

/**
 * Handles save data for metaprogression in game
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
	float Volume;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	float Sensitivity;
	
	UCOLDSNAPSaveGame();
};
