// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LF/Abilities/LFAbility.h"
#include "LFAbilityDash.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Custom))
class LF_API ULFAbilityDash : public ULFAbility
{
	GENERATED_BODY()

public:

	ULFAbilityDash();

	virtual void BeginAbility_Implementation(class ALFCharacter* Character) override;

	virtual bool CanUseAbility_Implementation() override;

	virtual void ActivateAbility_Implementation() override;

	virtual void UpdateAbility_Implementation(float DeltaTime) override;

	virtual void DeactivateAbility_Implementation() override;

};
