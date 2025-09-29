// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AttributeSet.h"
#include "GenericTeamAgentInterface.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class COLDSNAP_API APlayerCharacter : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<class UPlayerAbilitySystemComponent> PlayerAbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCharacterMovementComponent> CharacterMovementComp;	
	
	UPROPERTY()
	TObjectPtr<class UHealthAttributeSet> HealthSet;

	UPROPERTY()
	TObjectPtr<class UMovementAttributeSet> MovementSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float dashDuration = 0.5;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector dashForce = FVector(2000,2000,0);
	FVector baseDashForce = FVector(2000,2000,0);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float attackSpeed = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool allowDashDuringJump;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float verticalKnockbackMultiplier = 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID) override;
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; }

	void UpdateWalkSpeed(const FOnAttributeChangeData& Data);
	void UpdateDashDuration(const FOnAttributeChangeData& Data);
	void UpdateAttackSpeed(const FOnAttributeChangeData& Data);
	void UpdateAllowJumpDuringDash(const FOnAttributeChangeData& Data);
	void UpdateJumpForce(const FOnAttributeChangeData& Data);
	void UpdateVerticalKnockbackMultiplier(const FOnAttributeChangeData& Data);

private:
	FGenericTeamId TeamID;
};
