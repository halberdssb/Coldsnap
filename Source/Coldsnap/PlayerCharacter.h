// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AttributeSet.h"
#include "FEquippedUpgradeData.h"
#include "GenericTeamAgentInterface.h"
#include "PlayerCharacter.generated.h"

/*
 * Default player class for COLDSNAP
 *
 * Jeff Stevenson
 * 10.24.25
 */

UCLASS()
class COLDSNAP_API APlayerCharacter : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Equipped Upgrade Inventory
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<FEquippedUpgradeData, int32> EquippedUpgrades;
	
	virtual void Tick(float DeltaTime) override;

	// Handles GAS replication
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// returns GAS component
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// get and set team ID - used for enemy perception
	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID) override;
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; }

	// On GAS Attribute changed functions - subscribed to attribute change delegates in constructor
	void UpdateWalkSpeed(const FOnAttributeChangeData& Data);
	void UpdateMaxAcceleration(const FOnAttributeChangeData& Data);
	void UpdateGroundFriction(const FOnAttributeChangeData& Data);
	void UpdateFallingLateralFriction(const FOnAttributeChangeData& Data);
	void UpdateWalkingDeceleration(const FOnAttributeChangeData& Data);
	void UpdateFallingDeceleration(const FOnAttributeChangeData& Data);
	void UpdateAirControl(const FOnAttributeChangeData& Data);
	void UpdateAirBoostMultiplier(const FOnAttributeChangeData& Data);
	void UpdateDashForce(const FOnAttributeChangeData& Data);
	void UpdateAttackSpeed(const FOnAttributeChangeData& Data);
	void UpdateAllowJumpDuringDash(const FOnAttributeChangeData& Data);
	void UpdateJumpForce(const FOnAttributeChangeData& Data);
	void UpdateVerticalKnockbackMultiplier(const FOnAttributeChangeData& Data);
	void UpdateHorizontalKnockbackMultiplier(const FOnAttributeChangeData& Data);
	void UpdateTotalKnockbackMultiplier(const FOnAttributeChangeData& Data);
	void UpdateDamageMultiplier(const FOnAttributeChangeData& Data);
	void UpdateHeat(const FOnAttributeChangeData& Data);
	void UpdateMaxHeat(const FOnAttributeChangeData& Data);
	void UpdateHeatGainMultiplier(const FOnAttributeChangeData& Data);
	void UpdateHeatDrainValue(const FOnAttributeChangeData& Data);
	void UpdateHeatDrainMultiplier(const FOnAttributeChangeData& Data);
	void UpdateGravityScale(const FOnAttributeChangeData& Data);
	void UpdateLifeStealChance(const FOnAttributeChangeData& Data);
	void UpdateLifeStealHealAmount(const FOnAttributeChangeData& Data);

protected:
	virtual void BeginPlay() override;

	// GAS & Component Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<class UPlayerAbilitySystemComponent> PlayerAbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCharacterMovementComponent> CharacterMovementComp;

	// Attribute Sets
	UPROPERTY()
	TObjectPtr<class UHealthAttributeSet> HealthSet;
	UPROPERTY()
	TObjectPtr<class UPlayerMovementAttributeSet> MovementSet;
	UPROPERTY()
	TObjectPtr<class UHeatAttributeSet> HeatSet;

	// Hitbox creator component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UAttackHitboxManager> AttackHitboxManager;

	// Blueprint values changed by GAS attributes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float dashDuration = 0.4;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector dashForce = FVector(3000,3000,0);
	FVector baseDashForce = FVector(3000,3000,0);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float attackSpeed = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool allowDashDuringJump;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float verticalKnockbackMultiplier = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float horizontalKnockbackMultiplier = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float totalKnockbackMultiplier = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float damageMultiplier = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float lifeStealChance = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float lifeStealHealAmount = 1;

	// Subscribes all GAS Attribute functions to their respective Attributes
	void SubscribeToAttributeChangeEvents();

private:
	FGenericTeamId TeamID;

	// initializes ability system component 
	void SetUpAbilitySystemComponent();

	// fires proper GAS events from enhanced input actions
	void OnAbilityInputPressed(int32 InputID);
	void OnAbilityInputReleased(int32 InputID);
};
