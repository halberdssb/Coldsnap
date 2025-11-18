// Copyright 2025 Icebreak Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseOnHitEffect.generated.h"

/**
 * Base class for on-hit effect functions
 *
 * Jeff Stevenson
 * 11.17.25
 */

UCLASS(Blueprintable)
class COLDSNAP_API UBaseOnHitEffect : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "BaseOnHitEffect")
	void TryActivateOnHitEffect(FOnHitInfo HitInfo);
};
