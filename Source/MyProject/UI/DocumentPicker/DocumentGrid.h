// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "DocumentGridCard.h"
#include "DocumentGrid.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UDocumentGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddDocument(int32 DocumentIndex, FString DocumentName);
protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel* DocumentGrid;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDocumentGridCard> GridCardClass;
};
