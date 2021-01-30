// Fill out your copyright notice in the Description page of Project Settings.


#include "LF/Abilities/LFAbilityDash.h"

ULFAbilityDash::ULFAbilityDash()
{

}

void ULFAbilityDash::BeginAbility_Implementation(ALFCharacter* Character)
{
	Super::BeginAbility_Implementation(Character);
}

bool ULFAbilityDash::CanUseAbility_Implementation()
{
	return Super::CanUseAbility_Implementation();
}

void ULFAbilityDash::ActivateAbility_Implementation()
{
	Super::ActivateAbility_Implementation();
}

void ULFAbilityDash::UpdateAbility_Implementation(float DeltaTime)
{
	Super::UpdateAbility_Implementation(DeltaTime);
}

void ULFAbilityDash::DeactivateAbility_Implementation()
{
	Super::DeactivateAbility_Implementation();
}
