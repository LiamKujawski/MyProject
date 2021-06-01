// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DrawingGameMode.generated.h"

UCLASS()
class MYPROJECT_API ADrawingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	void Save();
	void Load();

protected:
	void BeginPlay() override;

private:
	// State
	FString SlotName;

};