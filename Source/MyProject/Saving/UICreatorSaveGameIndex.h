// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "UICreatorSaveGame.h"

#include "UICreatorSaveGameIndex.generated.h"

/**
 *
 */
UCLASS()
class MYPROJECT_API UUICreatorSaveGameIndex : public USaveGame
{
	GENERATED_BODY()

public:
	static UUICreatorSaveGameIndex* Load();
	bool Save();

	void AddSaveGame(UUICreatorSaveGame* SaveGame);
	TArray<FString> GetSlotNames() const { return SlotNames; }

private:
	static const FString SLOT_NAME;

	UPROPERTY()
	TArray<FString> SlotNames;

};