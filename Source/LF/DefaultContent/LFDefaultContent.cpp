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

void ULFDefaultContent::UpdateNextLevel(AActor* ThisWorld)
{
	if (ThisWorld->GetWorld() == MainLevel.Get())
	{
		NextLevel = Levels[0];
	}
	else if (ThisWorld->GetWorld() == Levels[Levels.Num() - 1].Get())
	{
		NextLevel = EndLevel;
	}
	else
	{
		for (int32 i = 0; i < Levels.Num(); ++i)
		{
			if (ThisWorld->GetWorld() == Levels[i].Get())
			{

				NextLevel = Levels[i + 1];
				break;
			}
		}
	}
}

