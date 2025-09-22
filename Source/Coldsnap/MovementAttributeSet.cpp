// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementAttributeSet.h"

UMovementAttributeSet::UMovementAttributeSet()
{
	InitGroundSpeed(30.0f);
	InitGroundAccel(6);
	InitGroundFriction(10);
	InitAirSpeed(35.0f);
	InitAirAccel(6.0f);
	InitAirFriction(7.0f);
}
