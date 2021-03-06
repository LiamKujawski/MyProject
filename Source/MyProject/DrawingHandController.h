// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stroke.h"

#include "HandControllerBase.h"
#include "DrawingHandController.generated.h"


UCLASS()
class MYPROJECT_API ADrawingHandController : public AHandControllerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrawingHandController();

	void TriggerPressed() override;
	void TriggerReleased() override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	// Config
	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeClass;

	// State
	AStroke* CurrentStroke;

};
