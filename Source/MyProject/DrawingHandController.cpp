// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawingHandController.h"
#include "Engine/World.h"

// Sets default values
ADrawingHandController::ADrawingHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADrawingHandController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADrawingHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentStroke)
	{
		CurrentStroke->Update(GetActorLocation());
	}
}

void ADrawingHandController::TriggerPressed()
{
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass);
	CurrentStroke->SetActorLocation(GetActorLocation());
}

void ADrawingHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}

