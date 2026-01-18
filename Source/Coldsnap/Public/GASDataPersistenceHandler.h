// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "COLDSNAPGameInstance.h"
#include "Coldsnap/PlayerAbilitySystemComponent.h"
#include "Components/ActorComponent.h"
#include "GASDataPersistenceHandler.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLDSNAP_API UGASDataPersistenceHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGASDataPersistenceHandler();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Data Persistence")
	bool SaveGASDataToGameInstance();

	UFUNCTION(BlueprintCallable, Category = "Data Persistence")
	bool LoadGASDataFromGameInstance();

	UFUNCTION(BlueprintCallable, Category = "Data Persistence")
	void InitializeDataTracking();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = General)
	TObjectPtr<AActor> Player;

	TObjectPtr<UPlayerAbilitySystemComponent> PlayerAbilitySystemComponent;
private:	

	TObjectPtr<UCOLDSNAPGameInstance> GameInstance;
};
