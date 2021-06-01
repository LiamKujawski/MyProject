// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawingGameMode.h"
#include "Saving/UICreatorSaveGame.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void ADrawingGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");

	UE_LOG(LogTemp, Warning, TEXT("SlotName: %s"), *SlotName);
}

void ADrawingGameMode::BeginPlay() 
{
	Super::BeginPlay();

	Load();
	UStereoLayerFunctionLibrary::HideSplashScreen();

}

void ADrawingGameMode::Save()
{
	UUICreatorSaveGame* Document = UUICreatorSaveGame::Load(SlotName);
	if (Document)
	{
		Document->SerializeFromWorld(GetWorld());
		Document->Save();
	}
}

void ADrawingGameMode::Load()
{
	UUICreatorSaveGame* Document = UUICreatorSaveGame::Load(SlotName);
	if (Document)
	{
		Document->DeserializeToWorld(GetWorld());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Slot Not Found: %s"), *SlotName);
	}

}