// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LF/LF.h"
#include "LFAbilityComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityEnabled, ELFAbilityType, Ability, bool, bHasBeenEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityStarted, ELFAbilityType, Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEnded, ELFAbilityType, Ability);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LF_API ULFAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULFAbilityComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AllowAbility(ELFAbilityType Type, bool bAllow);

	UFUNCTION(BlueprintCallable)
	bool IsAbilityAllowed(ELFAbilityType Type);


	UFUNCTION(BlueprintCallable)
	void ActivateAbilityByType(ELFAbilityType Type);

	UFUNCTION(BlueprintCallable)
	void DeactivateAbilityByType(ELFAbilityType Type);


public:

	UPROPERTY(BlueprintAssignable)
	FOnAbilityEnabled OnAbilityEnabled;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityStarted OnAbilityStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityEnded OnAbilityEnded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ELFAbilityType, TSubclassOf<class ULFAbility>> AbilityMapSubClasses;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ELFAbilityType, bool> AllowedAbilitiesMap;

	UPROPERTY(Transient, SkipSerialization)
	TMap<ELFAbilityType, class ULFAbility*> AbilityMap;

};
