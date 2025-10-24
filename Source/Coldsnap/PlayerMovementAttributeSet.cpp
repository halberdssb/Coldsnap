// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementAttributeSet.h"

UPlayerMovementAttributeSet::UPlayerMovementAttributeSet()
{
	// Initialize default values for all attributes
	InitGroundSpeed(BaseGroundSpeed);
	InitGroundAccel(BaseGroundAccel);
	InitGroundFriction(BaseGroundFriction);
	InitAirSpeed(BaseAirSpeed);
	InitAirAccel(BaseAirAccel);
	InitAirFriction(BaseAirFriction);
	InitDashForce(BaseDashForce);
	InitAttackSpeed(BaseAttackSpeed);
	InitDashJumpValue(BaseDashJumpValue);
	InitJumpForce(BaseJumpForce);
	InitVerticalKnockbackMultiplier(BaseVerticalKnockbackMultiplier);
}

void UPlayerMovementAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// Clamp speed to > 0
	if (Attribute == GetGroundSpeedAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, NewValue);
	}

	Super::PreAttributeChange(Attribute, NewValue);
}

void UPlayerMovementAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	// Fire on changed event for the changed atrribute
	
	if (Attribute == GetGroundSpeedAttribute())
	{
		OnGroundSpeedChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetGroundAccelAttribute())
	{
		OnGroundAccelChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetGroundFrictionAttribute())
	{
		OnGroundFrictionChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetAirSpeedAttribute())
	{
		OnAirSpeedChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetAirAccelAttribute	())
	{
		OnAirAccelChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetAirFrictionAttribute())
	{
		OnAirFrictionChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetDashForceAttribute())
	{
		OnDashForceChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetAttackSpeedAttribute())
	{
		OnAttackSpeedChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetDashJumpValueAttribute())
	{
		OnDashJumpValueChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetJumpForceAttribute())
	{
		OnJumpForceChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetVerticalKnockbackMultiplierAttribute())
	{
		OnVerticalKnockbackMultiplierChanged.Broadcast(this, OldValue, NewValue);
	}
}



