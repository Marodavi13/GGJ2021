// Fill out your copyright notice in the Description page of Project Settings.


#include "LFLibrary.h"
#include "LF/DefaultContent/LFDefaultContent.h"

ULFDefaultContent* ULFLibrary::GetLFDefaultContent()
{
	return ULFDefaultContent::Get();
}
