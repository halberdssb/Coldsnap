// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Slider.h"
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

	void NativeConstruct() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	// all focusable buttons for checking focus state
	UPROPERTY(BlueprintReadWrite, Category = "Navigable UI")
	TArray<UButton*> UIButtons;

	// all focusable sliders for checking focus state
	UPROPERTY(BlueprintReadWrite, Category = "Navigable UI")
	TArray<USlider*> UISliders;

	// button style to override focus colors for
	UPROPERTY(BlueprintReadWrite, Category = "Navigable UI")
	FButtonStyle ButtonStyle;

	// color of button when focused
	UPROPERTY(BlueprintReadWrite, Category = "Navigable UI")
	FLinearColor FocusedColor;

	// color of button when unfocused
	UPROPERTY(BlueprintReadWrite, Category = "Navigable UI")
	FLinearColor UnfocusedColor;

private:
	// gets all child button widgets in tree and adds them to UIButtons array
	void SetButtonAndSliderArrays();
	
	// gets button style and focus colors based on first child button style - ensures matching styles across all buttons
	void GetFocusColorReferences();

	// checks what button has focus and updates button states accordingly
	void UpdateFocusedButton();
};
