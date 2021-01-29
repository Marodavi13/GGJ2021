// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LF/LF.h"
#include "LFDefaultContent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class LF_API ULFDefaultContent : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static ULFDefaultContent* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FLinearColor GetAbilityColor(ELFAbilityType Ability) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<ELFAbilityType, FLinearColor> AbilityColors;
};
