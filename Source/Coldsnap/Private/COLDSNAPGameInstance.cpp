// Copyright 2025 Icebreak Studios. All rights reserved.


#include "COLDSNAPGameInstance.h"

void UCOLDSNAPGameInstance::SavePlayerGASData(TArray<FGameplayEffectSpec> InActiveGameplayEffects, float InCurrentHealth)
{
	ActiveGameplayEffects = InActiveGameplayEffects;
	UE_LOG(LogTemp, Warning, TEXT("Saved %d effects from player to game instance."), ActiveGameplayEffects.Num());
	CurrentHealth = InCurrentHealth;
}

TArray<FGameplayEffectSpec> UCOLDSNAPGameInstance::LoadPlayerGASData(float& OutCurrentHealth)
{
	OutCurrentHealth = CurrentHealth;
	return ActiveGameplayEffects;
}

void UCOLDSNAPGameInstance::SetCurrentHealth(float InCurrentHealth)
{
	CurrentHealth = InCurrentHealth;
}

const float UCOLDSNAPGameInstance::GetCurrentHealth()
{
	return CurrentHealth;
}

