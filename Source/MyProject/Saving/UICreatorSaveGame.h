// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UICreatorSaveGame.generated.h"
USTRUCT()
struct FStrokeState
{
	GENERATED_BODY()
		UPROPERTY()
		TSubclassOf<class AStroke> Class;
	UPROPERTY()
		TArray<FVector> ControlPoints;
};
/**
 *
 */
UCLASS()
class MYPROJECT_API UUICreatorSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	static UUICreatorSaveGame* Create();
	bool Save();
	static UUICreatorSaveGame* Load(FString SlotName);

	void SetState(FString NewState) { State = NewState; }
	FString GetState() const { return State; }

	void SerializeFromWorld(UWorld* World);
	void DeserializeToWorld(UWorld* World);

	FString GetSlotName() const { return SlotName; }

private:
	void ClearWorld(UWorld* World);

	//State
	UPROPERTY()
	FString State;

	UPROPERTY(VisibleAnywhere)
	FString SlotName;

	UPROPERTY()
	TArray<FStrokeState> Strokes;

};