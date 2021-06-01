
// Fill out your copyright notice in the Description page of Project Settings.
#include "UICreatorSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Misc/Guid.h"
#include "UICreatorSaveGameIndex.h"

#include "../Stroke.h"

UUICreatorSaveGame* UUICreatorSaveGame::Create()
{
	UUICreatorSaveGame* NewSaveGame = Cast<UUICreatorSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	NewSaveGame->SlotName = FGuid::NewGuid().ToString();
	if (!NewSaveGame->Save()) return nullptr;

	UUICreatorSaveGameIndex* Index = UUICreatorSaveGameIndex::Load();
	Index->AddSaveGame(NewSaveGame);
	Index->Save();

	return NewSaveGame;
}

bool UUICreatorSaveGame::Save()
{
	
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UUICreatorSaveGame* UUICreatorSaveGame::Load(FString SlotName)
{
	return Cast<UUICreatorSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
}
void UUICreatorSaveGame::SerializeFromWorld(UWorld* World)
{
	Strokes.Empty();
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		Strokes.Add(StrokeItr->SerializeToStruct());
	}
}
void UUICreatorSaveGame::DeserializeToWorld(UWorld* World)
{
	ClearWorld(World);
	for (FStrokeState StrokeState : Strokes)
	{
		AStroke::SpawnAndDeserializeFromStruct(World, StrokeState);
	}
}
void UUICreatorSaveGame::ClearWorld(UWorld* World)
{
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();
	}
}