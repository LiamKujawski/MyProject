// Fill out your copyright notice in the Description page of Project Settings.


#include "UICreatorSaveGameIndex.h"

#include "Kismet/GameplayStatics.h"

const FString UUICreatorSaveGameIndex::SLOT_NAME = "DocumentIndex";

UUICreatorSaveGameIndex* UUICreatorSaveGameIndex::Load()
{
	auto Index = Cast<UUICreatorSaveGameIndex>(UGameplayStatics::LoadGameFromSlot(SLOT_NAME, 0));
	if (!Index)
	{
		Index = Cast<UUICreatorSaveGameIndex>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
		Index->Save();
	}
	return Index;
}

bool UUICreatorSaveGameIndex::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SLOT_NAME, 0);
}

void UUICreatorSaveGameIndex::AddSaveGame(UUICreatorSaveGame* SaveGame)
{
	SlotNames.Add(SaveGame->GetSlotName());
}

