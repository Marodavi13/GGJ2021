// Fill out your copyright notice in the Description page of Project Settings.


#include "LF/Components/LFAbilityComponent.h"

// Sets default values for this component's properties
ULFAbilityComponent::ULFAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	for (int32 i = 1; i < (int32)ELFAbilityType::Count; ++i)
	{
		AllowedAbilitiesMap.Add((ELFAbilityType)i, false);
	}
}


// Called when the game starts
void ULFAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ULFAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULFAbilityComponent::AllowAbility(ELFAbilityType Type, bool bAllow)
{
	if (AllowedAbilitiesMap.Contains(Type))
	{
		AllowedAbilitiesMap[Type] = bAllow;
	}
}

bool ULFAbilityComponent::IsAbilityAllowed(ELFAbilityType Type)
{
	if (AllowedAbilitiesMap.Contains(Type))
	{
		return AllowedAbilitiesMap[Type];
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("CUIDADO, EL AllowedAbilitiesMap NO TIENE ESTA HABILIDAD!"));
	return false;
}
