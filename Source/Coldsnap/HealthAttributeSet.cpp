// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthAttributeSet.h"

/*
 * GAS Attribute Set for health
 * 
 * Jeff Stevenson
 * 10.24.25
 */

UHealthAttributeSet::UHealthAttributeSet()
{
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
}

