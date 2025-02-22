// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LF/LF.h"
#include "LFAbilityComponent.generated.h"

class ULFAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityEnabled, ELFAbilityType, Ability, bool, bHasBeenEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityStarted, ELFAbilityType, Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEnded, ELFAbilityType, Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityForbidden, ELFAbilityType, Ability);

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
	bool IsAbilityAllowed(ELFAbilityType Type) const;

	UFUNCTION(BlueprintCallable)
	void ActivateAbilityByType(ELFAbilityType Type);

	UFUNCTION(BlueprintCallable)
	void DeactivateAbilityByType(ELFAbilityType Type);

	void BroadcastAbilityDeactivated(TSubclassOf<ULFAbility> AbilityClass = nullptr);

	UFUNCTION(BlueprintPure)
	ELFAbilityType GetCurrentAbilityType() const { return CurrentAbility; }

	UFUNCTION(BlueprintPure)
	ULFAbility* GetCurrentAbility() const;

public:
	UPROPERTY(BlueprintAssignable)
	FOnAbilityEnabled OnAbilityEnabled;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityStarted OnAbilityStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityEnded OnAbilityEnded;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityForbidden OnAbilityForbidden;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ELFAbilityType, TSubclassOf<ULFAbility>> AbilityMapSubClasses;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ELFAbilityType, bool> AllowedAbilitiesMap;

	UPROPERTY(Transient, SkipSerialization)
	TMap<ELFAbilityType, ULFAbility*> AbilityMap;

	UPROPERTY(Transient, SkipSerialization, BlueprintReadOnly)
	ELFAbilityType CurrentAbility;
};
