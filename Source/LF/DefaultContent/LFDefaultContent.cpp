// Fill out your copyright notice in the Description page of Project Settings.


#include "./LFDefaultContent.h"

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
