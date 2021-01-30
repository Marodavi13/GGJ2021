// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LF/LF.h"
#include "LFDefaultContent.generated.h"

USTRUCT(BlueprintType)
struct FLFAbilityImages
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UTexture2D* EnabledTexture;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UTexture2D* DisabledTexture;
};

UCLASS(Blueprintable)
class LF_API ULFDefaultContent : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static ULFDefaultContent* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FLinearColor GetAbilityColor(ELFAbilityType Ability) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class UTexture2D* GetAbilityImage(ELFAbilityType Ability, bool bIsEnabled)const;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<ELFAbilityType, FLinearColor> AbilityColors;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<ELFAbilityType, FLFAbilityImages> AbilityImages;

};
