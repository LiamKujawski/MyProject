// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"
#include "DocumentPicker.h"
#include "ActionBar.generated.h"

/**
 *
 */
UCLASS()
class MYPROJECT_API UActionBar : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;

	void SetParentPicker(ADocumentPicker* NewParentPicker) { ParentPicker = NewParentPicker; }

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* AddButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* DeleteButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* ExitButton;

private:
	UFUNCTION()
		void AddButtonClicked()
	{
		UE_LOG(LogTemp, Warning, TEXT("Add clicked."));
	}

	UFUNCTION()
		void DeleteButtonClicked()
	{
		UE_LOG(LogTemp, Warning, TEXT("Delete clicked."));
	}


	UFUNCTION()
		void ExitButtonClicked() {
		UE_LOG(LogTemp, Warning, TEXT("Exit Clicked"));
	}

	UPROPERTY()
	ADocumentPicker* ParentPicker;

};