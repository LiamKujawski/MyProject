// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "DocumentPicker.generated.h"

UCLASS()
class MYPROJECT_API ADocumentPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADocumentPicker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;


	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* DocumentGrid;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* ActionBar;

};
