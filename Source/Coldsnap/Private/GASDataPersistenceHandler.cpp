// Copyright 2025 Icebreak Studios. All rights reserved.


#include "GASDataPersistenceHandler.h"

#include "COLDSNAPGameInstance.h"
#include "Coldsnap/HealthAttributeSet.h"

// Sets default values for this component's properties
UGASDataPersistenceHandler::UGASDataPersistenceHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGASDataPersistenceHandler::BeginPlay()
{
	Super::BeginPlay();
}




// Called every frame
void UGASDataPersistenceHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// returns if data was successfully saved to game isntance or not
bool UGASDataPersistenceHandler::SaveGASDataToGameInstance()
{
	// get all active effects
	TArray<FGameplayEffectSpec> ActiveEffects = PlayerAbilitySystemComponent->GetAllAppliedGameplayEffectSpecs();

	// return false if no game instance ref to save to
	if (GameInstance == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Game Instance is null - likely not COLDSNAPGameInstance - error detected in UGASDataPersistenceHandler"));
		return false;
	}

	// if game instance exists in correct type, save active effects to instance to be loaded in next scene
	float CurrentHealth = PlayerAbilitySystemComponent->GetSet<UHealthAttributeSet>()->GetHealthAttribute().GetNumericValue(PlayerAbilitySystemComponent->GetSet<UHealthAttributeSet>());
	UE_LOG(LogTemp, Log, TEXT("Current Health: %f"), CurrentHealth);
	GameInstance->SavePlayerGASData(ActiveEffects, CurrentHealth);
	return true;
}

bool UGASDataPersistenceHandler::LoadGASDataFromGameInstance()
{
	// return false if game instance does not exist
	if (GameInstance == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Instance is null - likely not COLDSNAPGameInstance - error detected in UGASDataPersistenceHandler"));
		return false;
	}

	// get and apply all active effects from last scene if they are permanent effects
	float CurrentHealth = 0;
	TArray<FGameplayEffectSpec> ActiveEffects = GameInstance->LoadPlayerGASData(CurrentHealth);
	for (FGameplayEffectSpec ActiveEffect : ActiveEffects)
	{
		if (ActiveEffect.GetDuration() == FGameplayEffectConstants::INFINITE_DURATION || ActiveEffect.GetDuration() == FGameplayEffectConstants::INSTANT_APPLICATION)
		{
			UE_LOG(LogTemp, Warning, TEXT("Applied ability %s"), *ActiveEffect.Def.GetName());
			PlayerAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(ActiveEffect);
		}
	}
	
	return true;
}

void UGASDataPersistenceHandler::InitializeDataTracking()
{
	// get owner and asc
	Player = GetOwner();
	if (UPlayerAbilitySystemComponent* TempASC = Player->GetComponentByClass<UPlayerAbilitySystemComponent>())
	{
		PlayerAbilitySystemComponent = TempASC;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find AbilitySystemComponent in GASDataPersistenceHandler on owning Actor %s"), *Player->GetName());
	}

	// get game instance reference
	if (UCOLDSNAPGameInstance* TempGameInstance = Cast<UCOLDSNAPGameInstance>(Player->GetGameInstance()))
	{
		UE_LOG(LogTemp, Error, TEXT("Game Instance Ref Found"));
		GameInstance = TempGameInstance;
	}

	LoadGASDataFromGameInstance();
}

