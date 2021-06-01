// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HandControllerBase.h"
#include "VRCharacter.generated.h"



UCLASS()
class MYPROJECT_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void UpdateDestinationMarker();

	void MoveForward(float throttle);
	void MoveRight(float throttle);

	void BeginTeleport();

	void RightSideTriggerPressed() { if (RightDrawingHandController) RightDrawingHandController->TriggerPressed(); }
	void RightSideTriggerReleased() { if (RightDrawingHandController)RightDrawingHandController->TriggerReleased();}

	
	void Save();


private:
	UPROPERTY(EditDefaultsOnly);
	TSubclassOf<AHandControllerBase> DrawingHandControllerClass;

	UPROPERTY(VisibleAnywhere);
	class UMotionControllerComponent* LeftController;

	UPROPERTY(VisibleAnywhere);
	class UMotionControllerComponent* RightController;


	UPROPERTY(VisibleAnywhere);
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere);
	class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere);
	class UStaticMeshComponent* DestinationMarker;



	// Refrence
	UPROPERTY();
	AHandControllerBase* RightDrawingHandController;

private:
	UPROPERTY(EditAnywhere);
	float MaxTeleportDistance = 2000;

};
