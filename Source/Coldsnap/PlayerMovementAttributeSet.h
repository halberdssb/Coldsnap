// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayerMovementAttributeSet.generated.h"

/**
 * GAS Attributes for Player Movement
 *
 * Jeff Stevenson
 * 10.25.25
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributeChangedEvent, UAttributeSet*, AttributeSet, float, OldValue, float, NewValue);

UCLASS()
class COLDSNAP_API UPlayerMovementAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UPlayerMovementAttributeSet();
	
	// Movement attributes 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData WalkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxAcceleration;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData GroundFriction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData FallingLateralFriction;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData WalkingDeceleration;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData FallingDeceleration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData AirControl;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData AirBoostMultiplier;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData DashForce;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData AttackSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData DashJumpValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData JumpForce;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData VerticalKnockbackMultiplier;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData HorizontalKnockbackMultiplier;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData TotalKnockbackMultiplier;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData DamageMultiplier;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData GravityScale;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData LifeStealChance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData LifeStealHealAmount;

	// Define attribute accessors for all attributes
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, WalkSpeed);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, MaxAcceleration);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, GroundFriction);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, FallingLateralFriction);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, WalkingDeceleration);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, FallingDeceleration);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, AirControl);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, AirBoostMultiplier);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, DashForce);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, AttackSpeed);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, DashJumpValue);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, JumpForce);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, VerticalKnockbackMultiplier);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, HorizontalKnockbackMultiplier);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, TotalKnockbackMultiplier);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, DamageMultiplier);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, GravityScale);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, LifeStealChance);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, LifeStealHealAmount);
	

	// attribute changed functions
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnWalkSpeedChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnMaxAccelerationChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnGroundFrictionChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnFallingLateralFrictionChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnWalkingDecelerationChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnFallingDecelerationChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnAirControlChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnAirBoostMultiplierChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnDashForceChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnAttackSpeedChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnDashJumpValueChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnJumpForceChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnVerticalKnockbackMultiplierChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHorizontalKnockbackMultiplierChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnTotalKnockbackMultiplierChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnDamageMultiplierChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnGravityScaleChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnLifeStealChanceChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnLifeStealHealAmountChanged;

private:
	// default values for attributes
	float BaseWalkSpeed = 600;
	float BaseMaxAcceleration = 4000;
	float BaseGroundFriction = 0;
	float BaseFallingLateralFriction = 0;
	float BaseWalkingDeceleration = 2048;
	float BaseFallingDeceleration = 0;
	float BaseAirControl = .95;
	float BaseAirBoostMultiplier = 2;
	float BaseDashForce = 4;
	float BaseAttackSpeed = 1.4;
	float BaseDashJumpValue = 0;
	float BaseJumpForce = 420;
	float BaseVerticalKnockbackMultiplier = 1;
	float BaseHorizontalKnockbackMultiplier = 1;
	float BaseTotalKnockbackMultiplier = 1;
	float BaseDamageMultiplier = 1;
	float BaseGravityScale = 1;
	float BaseLifeStealChance = 1;
	float BaseLifeStealHealAmount = 20;
};
