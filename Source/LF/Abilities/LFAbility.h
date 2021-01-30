// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LFAbility.generated.h"

class ALFCharacter;
class ULFAbilityComponent;

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Custom))
class LF_API ULFAbility : public UObject
{
	GENERATED_BODY()
	
public:
	
	ULFAbility();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BeginAbility(ALFCharacter* Character, ULFAbilityComponent* AbilityComponent = nullptr);

	virtual void BeginAbility_Implementation(ALFCharacter* Character, ULFAbilityComponent* AbilityComponent = nullptr);


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanUseAbility();

	virtual bool CanUseAbility_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ActivateAbility();

	virtual void ActivateAbility_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateAbility(float DeltaTime);

	virtual void UpdateAbility_Implementation(float DeltaTime);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DeactivateAbility();

	virtual void DeactivateAbility_Implementation();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ALFCharacter* OwnerCharacter;

	UPROPERTY(BlueprintReadOnly)
	ULFAbilityComponent* OwnerAbilityComponent;

};
