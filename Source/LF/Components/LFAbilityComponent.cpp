// Fill out your copyright notice in the Description page of Project Settings.


#include "LF/Components/LFAbilityComponent.h"
#include "LF/Abilities/LFAbility.h"
#include "LF/Actors/Character/LFCharacter.h"


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

	for (const TPair<ELFAbilityType, TSubclassOf<ULFAbility>>& pair : AbilityMapSubClasses)
	{
		ULFAbility* InstanciatedAbility = NewObject<ULFAbility>(this, pair.Value);
		AbilityMap.Add(pair.Key, InstanciatedAbility);

		InstanciatedAbility->BeginAbility(Cast<ALFCharacter>(GetOwner()));
	}
}


// Called every frame
void ULFAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentAbility != ELFAbilityType::None)
	{
		AbilityMap[CurrentAbility]->UpdateAbility(DeltaTime);
	}
}

void ULFAbilityComponent::AllowAbility(ELFAbilityType Type, bool bAllow)
{
	if (AllowedAbilitiesMap.Contains(Type))
	{
		AllowedAbilitiesMap[Type] = bAllow;

		OnAbilityEnabled.Broadcast(Type, bAllow);
	}
}

bool ULFAbilityComponent::IsAbilityAllowed(ELFAbilityType Type) const
{
	if (AllowedAbilitiesMap.Contains(Type))
	{
		return AllowedAbilitiesMap[Type];
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("CUIDADO, EL AllowedAbilitiesMap NO TIENE ESTA HABILIDAD!"));
	}
	return false;
}

void ULFAbilityComponent::ActivateAbilityByType(ELFAbilityType Type)
{
	if (CurrentAbility == ELFAbilityType::None && IsAbilityAllowed(Type) && AbilityMap.Contains(Type) && AbilityMap[Type]->CanUseAbility())
	{
		CurrentAbility = Type;
		AbilityMap[Type]->ActivateAbility();
		OnAbilityStarted.Broadcast(Type);
	}
}

void ULFAbilityComponent::DeactivateAbilityByType(ELFAbilityType Type)
{
	if (CurrentAbility == Type && AbilityMap.Contains(Type))
	{
		CurrentAbility = ELFAbilityType::None;
		AbilityMap[Type]->DeactivateAbility();
		OnAbilityEnded.Broadcast(Type);
	}
}

ULFAbility* ULFAbilityComponent::GetCurrentAbility() const
{
	ULFAbility* ReturnedAbility = nullptr;
	if(AbilityMap.Contains(CurrentAbility))
	{
		ReturnedAbility = AbilityMap[CurrentAbility];
	}
	return ReturnedAbility;
}
