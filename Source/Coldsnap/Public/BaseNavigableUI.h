// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "BaseNavigableUI.generated.h"

/**
 * Base class of all widgets with navigable UI - handles button navigation visuals
 *
 * Jeff Stevenson
 * 11.23.25
 */
UCLASS()
class COLDSNAP_API UBaseNavigableUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Navigable UI")
	TArray<UButton*> UIButtons;

	//UPROPERTY(BlueprintReadWrite, Category = "Navigable UI")
	//FButtonStyle ButtonStyle;
};
