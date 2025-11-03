// Copyright 2025 Icebreak Studios. All rights reserved.


#include "GameplayAbilityInputData.h"

UGameplayAbilityInputData::UGameplayAbilityInputData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const TSet<FGameplayAbilityInputMapping> UGameplayAbilityInputData::GetInputMappings()
{
	return AbilityInputMappings;
}

#if WITH_EDITOR
void UGameplayAbilityInputData::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	// get property that was changed in editor
	const FProperty* ChangedProperty = PropertyChangedEvent.Property;

	// if property in input mappings was changed, create correct ID and organization for input mappings TSet
	if (ChangedProperty && ChangedProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UGameplayAbilityInputData, AbilityInputMappings) && !AbilityInputMappings.IsEmpty())
	{
		// save TSet to temp array
		TArray<FGameplayAbilityInputMapping> TempInputMappingsArray = AbilityInputMappings.Array();
		Modify();

		// clear saved input mappings and re-add valid mappings w/ IDs
		AbilityInputMappings.Empty();

		for (int32 i = 0; i < TempInputMappingsArray.Num(); i++)
		{
			FGameplayAbilityInputMapping CurrentInputMapping = TempInputMappingsArray[i];
			if (!AbilityInputMappings.Contains(CurrentInputMapping))
			{
				// ensure ID is index of mapping within array
				CurrentInputMapping.InputID = AbilityInputMappings.Num();
				AbilityInputMappings.Add(CurrentInputMapping);
			}
		}
	}
}
#endif
