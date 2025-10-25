// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayerMovementAttributeSet.generated.h"

/**
 * GAS Attributes for Player Movement
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
	FGameplayAttributeData GroundSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData GroundAccel;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData GroundFriction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData AirSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData AirAccel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData AirFriction;

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

	// Define attribute accessors for all attributes
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, GroundSpeed);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, GroundAccel);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, GroundFriction);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, AirSpeed);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, AirAccel);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, AirFriction);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, DashForce);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, AttackSpeed);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, DashJumpValue);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, JumpForce);
	ATTRIBUTE_ACCESSORS_BASIC(UPlayerMovementAttributeSet, VerticalKnockbackMultiplier);
	

	// attribute changed functions
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnGroundSpeedChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnGroundAccelChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnGroundFrictionChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnAirSpeedChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnAirAccelChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnAirFrictionChanged;
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

private:
	// default values for attributes
	float BaseGroundSpeed = 600;
	float BaseGroundAccel = 6;
	float BaseGroundFriction = 10;
	float BaseAirSpeed = 600;
	float BaseAirAccel = 6.0;
	float BaseAirFriction = 7.0;
	float BaseDashForce = 1;
	float BaseAttackSpeed = 1.4;
	float BaseDashJumpValue = 0;
	float BaseJumpForce = 420;
	float BaseVerticalKnockbackMultiplier = 1;
};
