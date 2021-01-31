// Fill out your copyright notice in the Description page of Project Settings.


#include "./LFDefaultContent.h"
#include "PaperSprite.h"
#include "Engine/World.h"

ULFDefaultContent* ULFDefaultContent::Get()
{
	ULFDefaultContent* DefaultContent = nullptr;

	if (GEngine)
	{
		DefaultContent = Cast<ULFDefaultContent>(GEngine->GameSingleton);
	}

	return DefaultContent;
}

FLinearColor ULFDefaultContent::GetAbilityColor(ELFAbilityType Ability) const
{
	FLinearColor ReturnedColor = FLinearColor::Black;

	const FLinearColor* Color = AbilityColors.Find(Ability);
	if (Color)
	{
		ReturnedColor = *Color;
	}

	return ReturnedColor;
}

UTexture2D* ULFDefaultContent::GetAbilityImage(ELFAbilityType Ability, bool bIsEnabled) const
{
	UTexture2D* ReturnedTexture = nullptr;
	const FLFAbilityImages* Images = AbilityImages.Find(Ability);
	if (Images)
	{
		ReturnedTexture = bIsEnabled ? Images->EnabledTexture : Images->DisabledTexture;
	}

	return ReturnedTexture;
}


TArray<UPaperSprite*> ULFDefaultContent::GetOnAltarSprites(ELFAbilityType Ability)
{
	TArray<UPaperSprite*> SpritesArray;

	FLFAltarSprites Sprites = AltarSprites[Ability];
	SpritesArray.Add(Sprites.OnSprite);
	SpritesArray.Add(Sprites.EyesSprite);
	SpritesArray.Add(Sprites.GlowSprite);
	SpritesArray.Add(Sprites.GemSprite);

	return SpritesArray;
}

TArray<UPaperSprite*> ULFDefaultContent::GetOffAltarSprites(ELFAbilityType Ability)
{
	TArray<UPaperSprite*> SpritesArray;

	FLFAltarSprites Sprites = AltarSprites[Ability];
	SpritesArray.Add(Sprites.OffSprite);
	SpritesArray.Add(nullptr);
	SpritesArray.Add(nullptr);
	SpritesArray.Add(nullptr);

	return SpritesArray;
}

TSoftObjectPtr<UWorld> ULFDefaultContent::GetNextLevel(AActor* ThisWorld)
{
	TSoftObjectPtr<UWorld> ReturnedWorld = nullptr;

	if (ThisWorld->GetWorld() == MainLevel.Get())
	{
		ReturnedWorld = Levels[0];
	}
	else if (ThisWorld->GetWorld() == Levels[Levels.Num() - 1].Get())
	{
		ReturnedWorld = EndLevel;
	}
	else
	{
		for (int32 i = 0; i < Levels.Num(); ++i)
		{
			if (ThisWorld->GetWorld() == Levels[i].Get())
			{

				ReturnedWorld = Levels[i + 1];
				break;
			}
		}
	}
	return ReturnedWorld;
}

TSoftObjectPtr<UWorld> ULFDefaultContent::GetCurrentLevel(AActor* ThisWorld)
{
	TSoftObjectPtr<UWorld> ReturnedWorld = nullptr;

	if (ThisWorld->GetWorld() == MainLevel.Get())
	{
		ReturnedWorld = MainLevel;
	}
	else if (ThisWorld->GetWorld() == EndLevel.Get())
	{
		ReturnedWorld = EndLevel;
	}
	else
	{
		for (int32 i = 0; i < Levels.Num(); ++i)
		{
			if (ThisWorld->GetWorld() == Levels[i].Get())
			{

				ReturnedWorld = Levels[i];
				break;
			}
		}
	}
	return ReturnedWorld;
}

TSoftObjectPtr<UWorld> ULFDefaultContent::GetLevel(int32 ID)
{
	TSoftObjectPtr<UWorld> ReturnedWorld = Levels[ID];

	return ReturnedWorld;

}

