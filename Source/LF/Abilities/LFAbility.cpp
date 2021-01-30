// Fill out your copyright notice in the Description page of Project Settings.


#include "LF/Abilities/LFAbility.h"


ULFAbility::ULFAbility()
{

}

void ULFAbility::BeginAbility_Implementation(ALFCharacter* Character)
{
	OwnerCharacter = Character;
}

bool ULFAbility::CanUseAbility_Implementation()
{
	return true;
}

void ULFAbility::ActivateAbility_Implementation()
{

}

void ULFAbility::UpdateAbility_Implementation(float DeltaTime)
{

}

void ULFAbility::DeactivateAbility_Implementation()
{

}
