// Copyright 2025 Icebreak Studios. All rights reserved.


#include "BaseNavigableUI.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"


void UBaseNavigableUI::NativeConstruct()
{
	Super::NativeConstruct();

	SetButtonAndSliderArrays();
	GetFocusColorReferences();

	for (UButton* Button : UIButtons)
	{
		Button->SetStyle(ButtonStyle);	
	}
}

void UBaseNavigableUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	UpdateFocusedButton();
}

void UBaseNavigableUI::SetButtonAndSliderArrays()
{
	// get all child widgets
	TArray<UWidget*> ChildWidgets;
	this->WidgetTree->GetAllWidgets(ChildWidgets);

	// search child widgets for buttons and add to array
	for (UWidget* Widget : ChildWidgets)
	{
		if (Widget->IsA(UButton::StaticClass()))
		{
			UButton* WidgetButton = Cast<UButton>(Widget);
			UIButtons.Add(WidgetButton);
		}
	}

	// set slider array
	// search child widgets for buttons and add to array
	for (UWidget* Widget : ChildWidgets)
	{
		if (Widget->IsA(USlider::StaticClass()))
		{
			USlider* WidgetSlider = Cast<USlider>(Widget);
			UISliders.Add(WidgetSlider);
		}
	}
}

void UBaseNavigableUI::GetFocusColorReferences()
{
	if (UIButtons.Num() > 0)
	{
		// use first button as de-facto template for style colors
		UButton* TemplateButton = UIButtons[0];
		ButtonStyle = TemplateButton->GetStyle();
		FocusedColor = ButtonStyle.Hovered.TintColor.GetSpecifiedColor();
		UnfocusedColor = ButtonStyle.Normal.TintColor.GetSpecifiedColor();
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("No buttons in %s to get focus colors from."), *GetName());
	}
}

void UBaseNavigableUI::UpdateFocusedButton()
{
	if (!IsInViewport() || UIButtons.Num() <= 0) return;
	
	bool buttonHasFocus = false;
	bool IsMouseHovered = false;
	UButton* FocusedButton = nullptr;
	for (UButton* Button : UIButtons)
	{
		// update button color based on focus
		if (Button->HasKeyboardFocus())
		{
			if (Button->IsHovered())
			{
				IsMouseHovered = true;
			}
			
			buttonHasFocus = true;
			FocusedButton = Button;
		}
		else
		{
			Button->SetBackgroundColor(UnfocusedColor);
		}
	}

	USlider* FocusedSlider = nullptr;
	for (USlider* Slider : UISliders)
	{
		// update button color based on focus
		if (Slider->HasKeyboardFocus())
		{
			if (Slider->IsHovered())
			{
				IsMouseHovered = true;
			}
			buttonHasFocus = true;
			FocusedSlider = Slider;
		}
		else
		{
			Slider->SetSliderBarColor(UnfocusedColor);
		}
	}

	// if mouse is hovering over an element, don't highlight others
	if (IsMouseHovered) return;
	
	// updated focused button/slider color
	if (FocusedButton != nullptr)
	{
		FocusedButton->SetBackgroundColor(FocusedColor);
	}
	else if (FocusedSlider != nullptr)
	{
		FocusedSlider->SetSliderBarColor(UnfocusedColor);
	}
	// ensure some button always has focus
	else if (!buttonHasFocus)
	{
		UIButtons[0]->SetKeyboardFocus();
		UIButtons[0]->SetBackgroundColor(FocusedColor);
	}
}
