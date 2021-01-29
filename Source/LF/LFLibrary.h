// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LFLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LF_API ULFLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure)
	static class ULFDefaultContent* GetLFDefaultContent();
};
