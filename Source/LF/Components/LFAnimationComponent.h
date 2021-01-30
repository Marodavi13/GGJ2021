// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LF/LF.h"
#include "LFAnimationComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LF_API ULFAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULFAnimationComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetCurrentAnimation(ELFAbilityType AbilityType);

	void UpdateAnimationBySpeed();
	void UpdateDirection(const FVector& PlayerVelocity);
	void UpdateFlipbook();
	

	UFUNCTION()
	void OnAbilityStarted(ELFAbilityType AbilityType);
		
	UFUNCTION()
	void OnAbilityEnded(ELFAbilityType AbilityType);

protected:

	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	TMap<ELFAbilityType, UPaperFlipbook*> AbilitiesAnimations;

	UPROPERTY(Transient, SkipSerialization, BlueprintReadOnly)
	class UPaperFlipbook* CurrentAnimation;
		
	UPROPERTY(Transient, SkipSerialization, BlueprintReadOnly)
	ELFAbilityType CurrentAbility;

	UPROPERTY(Transient, SkipSerialization, BlueprintReadOnly)
	class APaperCharacter* OwnerCharacter;
};
