// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementAttributeSet.h"

UMovementAttributeSet::UMovementAttributeSet()
{
	InitGroundSpeed(600);
	InitGroundAccel(6);
	InitGroundFriction(10);
	InitAirSpeed(600);
	InitAirAccel(6.0f);
	InitAirFriction(7.0f);
	InitDashForce(1);
	InitAttackSpeed(1);
	InitDashJumpValue(0);
	InitJumpForce(420);
	InitVerticalKnockbackMultiplier(1);
}

void UMovementAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetGroundSpeedAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, NewValue);
	}

	Super::PreAttributeChange(Attribute, NewValue);
}

void UMovementAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
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



