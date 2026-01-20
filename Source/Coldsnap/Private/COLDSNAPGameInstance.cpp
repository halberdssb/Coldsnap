// Copyright 2025 Icebreak Studios. All rights reserved.


#include "COLDSNAPGameInstance.h"

void UCOLDSNAPGameInstance::SavePlayerGASData(TArray<FGameplayEffectSpec> InActiveGameplayEffects)
{
	ActiveGameplayEffects = InActiveGameplayEffects;
	UE_LOG(LogTemp, Warning, TEXT("Saved %d effects from player to game instance."), ActiveGameplayEffects.Num());

}

TArray<FGameplayEffectSpec> UCOLDSNAPGameInstance::LoadPlayerGASData()
{
	return ActiveGameplayEffects;
}
