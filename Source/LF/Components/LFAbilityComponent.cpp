// Fill out your copyright notice in the Description page of Project Settings.


#include "LF/Components/LFAbilityComponent.h"

// Sets default values for this component's properties
ULFAbilityComponent::ULFAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULFAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULFAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULFAbilityComponent::AllowAbility(ELFAbilityType Type, bool bAllow)
{
	if (AllowedAbilities.Contains(Type))
	{
		AllowedAbilities[Type] = bAllow;
	}
}

bool ULFAbilityComponent::IsAbilityAllowed(ELFAbilityType Type)
{
	if (AllowedAbilities.Contains(Type))
	{
		return AllowedAbilities[Type];
	}

	return false;
}
