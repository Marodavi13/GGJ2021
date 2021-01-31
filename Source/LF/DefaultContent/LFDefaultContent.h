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

USTRUCT(BlueprintType)
struct FLFAltarSprites
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UPaperSprite* OffSprite;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UPaperSprite* OnSprite;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UPaperSprite* EyesSprite;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UPaperSprite* GlowSprite;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UPaperSprite* GemSprite;
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

	UFUNCTION(BlueprintCallable)
	TArray<UPaperSprite*>GetOnAltarSprites(ELFAbilityType Ability);
	
	UFUNCTION(BlueprintCallable)
	TArray<UPaperSprite*> GetOffAltarSprites(ELFAbilityType Ability);

	UFUNCTION(BlueprintCallable)
	TSoftObjectPtr<UWorld> GetNextLevel(AActor* ThisWorld);
	UFUNCTION(BlueprintCallable)
	TSoftObjectPtr<UWorld> GetCurrentLevel(AActor* ThisWorld);

	UFUNCTION(BlueprintCallable)
	TSoftObjectPtr<UWorld> GetLevel(int32 ID);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<ELFAbilityType, FLinearColor> AbilityColors;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<ELFAbilityType, FLFAbilityImages> AbilityImages;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<ELFAbilityType, FLFAltarSprites> AltarSprites;

	//Levels
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSoftObjectPtr<UWorld>> Levels;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> MainLevel;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> EndLevel;

	UPROPERTY(Transient, SkipSerialization, BlueprintReadOnly)
	TSoftObjectPtr<UWorld> NextLevel;
};
