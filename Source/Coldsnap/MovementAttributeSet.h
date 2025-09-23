// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MovementAttributeSet.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributeChangedEvent, UAttributeSet*, AttributeSet, float, OldValue, float, NewValue);

UCLASS()
class COLDSNAP_API UMovementAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UMovementAttributeSet();

	//void UHealthAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
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
	
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, GroundSpeed);
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, GroundAccel);
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, GroundFriction);
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, AirSpeed);
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, AirAccel);
	ATTRIBUTE_ACCESSORS_BASIC(UMovementAttributeSet, AirFriction);

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
	
};
