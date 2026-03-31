// Copyright 2025 Icebreak Studios. All rights reserved.

#include "COLDSNAPGameInstance.h"

#include "Coldsnap/PlayerCharacter.h"

// takes in GAS data (typically from GAS data handler) and saves it to instance
void UCOLDSNAPGameInstance::SavePlayerGASData(TArray<FGameplayEffectSpec> InActiveGameplayEffects, float InCurrentHealth)
{
	ActiveGameplayEffects = InActiveGameplayEffects;
	UE_LOG(LogTemp, Warning, TEXT("Saved %d effects from player to game instance."), ActiveGameplayEffects.Num());
	CurrentHealth = InCurrentHealth;
}

// loads the player's saved gas data for load on new scene
TArray<FGameplayEffectSpec> UCOLDSNAPGameInstance::LoadPlayerGASData(float& OutCurrentHealth)
{
	OutCurrentHealth = CurrentHealth;
	return ActiveGameplayEffects;
}

void UCOLDSNAPGameInstance::Init()
{
	Super::Init();
}

void UCOLDSNAPGameInstance::SetCurrentHealth(float InCurrentHealth)
{
	CurrentHealth = InCurrentHealth;
}

const float UCOLDSNAPGameInstance::GetCurrentHealth()
{
	return CurrentHealth;
}

void UCOLDSNAPGameInstance::ResetRunData()
{
	ActiveGameplayEffects.Empty();
	CurrentHealth = DefaultHealth;
	RunStartTime = 0;
	StagesCleared = 0;
	TotalFinishedStageTime = 0;
	XPGained = 0;
}

