// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class COLDSNAP_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UHealthAttributeSet();

	//void UHealthAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, Health);
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, MaxHealth);
};
