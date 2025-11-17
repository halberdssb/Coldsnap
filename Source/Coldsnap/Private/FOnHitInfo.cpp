// Copyright 2025 Icebreak Studios. All rights reserved.


#include "FOnHitInfo.h"

FOnHitInfo::FOnHitInfo()
{
	this->HitTarget = nullptr;
	this->HitPerformer = nullptr;
	this->HitLocation = FVector::ZeroVector;
	this->TargetKilled = false;
}

FOnHitInfo::FOnHitInfo(AActor* HitTarget, AActor* HitPerformer, FVector HitLocation, bool TargetKilled)
{
	this->HitTarget = HitTarget;
	this->HitPerformer = HitPerformer;
	this->HitLocation = HitLocation;
	this->TargetKilled = TargetKilled;
}

FOnHitInfo::~FOnHitInfo()
{
}
