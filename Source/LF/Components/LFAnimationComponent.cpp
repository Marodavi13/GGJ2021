// Fill out your copyright notice in the Description page of Project Settings.


#include "LFAnimationComponent.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

// Sets default values for this component's properties
ULFAnimationComponent::ULFAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bIsDashing = false;
}


// Called when the game starts
void ULFAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<APaperCharacter>(GetOwner());
}


// Called every frame
void ULFAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (OwnerCharacter)
	{
		const FVector PlayerVelocity = OwnerCharacter->GetVelocity();
		const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

		UpdateFlipbook(PlayerSpeedSqr);
		UpdateDirection(PlayerVelocity);
	}
}

void ULFAnimationComponent::UpdateFlipbook(const float PlayerSpeedSqr)
{
	// Are we moving or standing still?
	UPaperFlipbook* DesiredAnimation;
	
	if (bIsDashing)
		DesiredAnimation = DashAnimation;
	else
		DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? RunningAnimation : IdleAnimation;

	if (OwnerCharacter->GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		check(OwnerCharacter->GetSprite()->SetFlipbook(DesiredAnimation));
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
