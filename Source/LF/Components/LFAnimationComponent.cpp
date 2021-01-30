// Fill out your copyright notice in the Description page of Project Settings.


#include "LFAnimationComponent.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "LFAbilityComponent.h"

// Sets default values for this component's properties
ULFAnimationComponent::ULFAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void ULFAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<APaperCharacter>(GetOwner());

	CurrentAbility = ELFAbilityType::None;
	SetCurrentAnimation(CurrentAbility);
	
	ULFAbilityComponent* Ability = OwnerCharacter->FindComponentByClass<ULFAbilityComponent>();
	if (Ability)
	{
		Ability->OnAbilityStarted.AddDynamic(this, &ULFAnimationComponent::OnAbilityStarted);
		Ability->OnAbilityEnded.AddDynamic(this, &ULFAnimationComponent::OnAbilityEnded);
	}
}

void ULFAnimationComponent::SetCurrentAnimation(ELFAbilityType AbilityType)
{
	if (AbilitiesAnimations.Contains(AbilityType))
	{
		CurrentAbility = AbilityType;
		CurrentAnimation = AbilitiesAnimations[AbilityType];
	}
	else
	{
		UpdateAnimationBySpeed();
	}
	
	OwnerCharacter->GetSprite()->OnFinishedPlaying.Clear();
	OwnerCharacter->GetSprite()->SetLooping(true);

	UpdateFlipbook();
}

void ULFAnimationComponent::ClearCurrentAnimation()
{
	SetCurrentAnimation(ELFAbilityType::None);
}

void ULFAnimationComponent::UpdateAnimationBySpeed()
{
	const FVector PlayerVelocity = OwnerCharacter->GetVelocity();
	const float PlayerSpeed = PlayerVelocity.Size2D();

	CurrentAnimation = PlayerSpeed > 0.f ? RunningAnimation : IdleAnimation;

}
void ULFAnimationComponent::OnAbilityStarted(ELFAbilityType AbilityType)
{
	SetCurrentAnimation(AbilityType);
}

void ULFAnimationComponent::OnAbilityEnded(ELFAbilityType AbilityType)
{
	CurrentAbility = ELFAbilityType::None;
	SetCurrentAnimation(CurrentAbility);

	if (AbilitiesFinishingAnimations.Contains(AbilityType))
	{
		CurrentAnimation = AbilitiesFinishingAnimations[AbilityType];
		OwnerCharacter->GetSprite()->OnFinishedPlaying.AddDynamic(this, &ThisClass::ClearCurrentAnimation);
		OwnerCharacter->GetSprite()->SetLooping(false);
		UpdateFlipbook();
	}
}

// Called every frame
void ULFAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (OwnerCharacter)
	{
		const FVector PlayerVelocity = OwnerCharacter->GetVelocity();
		UpdateDirection(PlayerVelocity);
		
		if (CurrentAbility == ELFAbilityType::None)
		{
			if(!OwnerCharacter->GetSprite()->OnFinishedPlaying.IsBound())
			{
				UpdateAnimationBySpeed();
				UpdateFlipbook();
			}
		}
	}
}

void ULFAnimationComponent::UpdateFlipbook()
{
	if (OwnerCharacter->GetSprite()->GetFlipbook() != CurrentAnimation)
	{
		OwnerCharacter->GetSprite()->SetFlipbook(CurrentAnimation);
		OwnerCharacter->GetSprite()->Play();
	}
}

void ULFAnimationComponent::UpdateDirection(const FVector& PlayerVelocity)
{
	// Now setup the rotation of the controller based on the direction we are travelling
	float TravelDirection = PlayerVelocity.X;
	// Set the rotation so that the character faces his direction of travel.
	AController* Controller = OwnerCharacter->GetController();
	if (Controller != nullptr)
	{
		if (TravelDirection < 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0, 180.0f, 0.0f));
		}
		else if (TravelDirection > 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	}
}
