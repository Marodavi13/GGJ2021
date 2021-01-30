// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LFAbility.generated.h"

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
	void BeginAbility(class ALFCharacter* Character);

	virtual void BeginAbility_Implementation(class ALFCharacter* Character);


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
	class ALFCharacter* OwnerCharacter;

};
