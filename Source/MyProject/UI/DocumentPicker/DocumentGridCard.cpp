// Fill out your copyright notice in the Description page of Project Settings.

#include "DocumentGridCard.h"

#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void UDocumentGridCard::SetDocumentName(FString NewDocumentName)
{
	DocumentName = NewDocumentName;

	SlotName->SetText(FText::FromString(DocumentName));

	CardButton->OnClicked.AddDynamic(this, &UDocumentGridCard::CardButtonClicked);
}

void UDocumentGridCard::CardButtonClicked()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen();

	// Loads up the map(MainMap)
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMap"), true, "SlotName=" + DocumentName);
}