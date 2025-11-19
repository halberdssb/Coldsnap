// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementAttributeSet.h"

UPlayerMovementAttributeSet::UPlayerMovementAttributeSet()
{
	// Initialize default values for all attributes
	InitWalkSpeed(BaseWalkSpeed);
	InitMaxAcceleration(BaseMaxAcceleration);
	InitGroundFriction(BaseGroundFriction);
	InitFallingLateralFriction(BaseFallingLateralFriction);
	InitWalkingDeceleration(BaseWalkingDeceleration);
	InitFallingDeceleration(BaseFallingDeceleration);
	InitAirControl(BaseAirControl);
	InitAirBoostMultiplier(BaseAirBoostMultiplier);
	InitDashForce(BaseDashForce);
	InitAttackSpeed(BaseAttackSpeed);
	InitDashJumpValue(BaseDashJumpValue);
	InitJumpForce(BaseJumpForce);
	InitVerticalKnockbackMultiplier(BaseVerticalKnockbackMultiplier);
	InitHorizontalKnockbackMultiplier(BaseHorizontalKnockbackMultiplier);
	InitTotalKnockbackMultiplier(BaseTotalKnockbackMultiplier);
	InitDamageMultiplier(BaseDamageMultiplier);
	InitGravityScale(BaseGravityScale);
	InitLifeStealChance(BaseLifeStealChance);
	InitLifeStealHealAmount(BaseLifeStealHealAmount);
}

void UPlayerMovementAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// Clamp speed to > 0
	if (Attribute == GetWalkSpeedAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, NewValue);
	}

	Super::PreAttributeChange(Attribute, NewValue);
}

void UPlayerMovementAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	// Fire on changed event for the changed atrribute
	
	if (Attribute == GetWalkSpeedAttribute())
	{
		OnWalkSpeedChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetMaxAccelerationAttribute())
	{
		OnMaxAccelerationChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetGroundFrictionAttribute())
	{
		OnGroundFrictionChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetFallingDecelerationAttribute())
	{
		OnFallingLateralFrictionChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetWalkingDecelerationAttribute())
	{
		OnWalkingDecelerationChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetFallingDecelerationAttribute())
	{
		OnFallingDecelerationChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetAirControlAttribute())
	{
		OnAirControlChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetAirBoostMultiplierAttribute())
	{
		OnAirBoostMultiplierChanged.Broadcast(this, OldValue, NewValue);
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
	else if (Attribute == GetGravityScaleAttribute())
	{
		OnGravityScaleChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetLifeStealChanceAttribute())
	{
		OnLifeStealChanceChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetLifeStealHealAmountAttribute())
	{
		OnLifeStealHealAmountChanged.Broadcast(this, OldValue, NewValue);
	}
}



