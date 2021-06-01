// Fill out your copyright notice in the Description page of Project Settings.


#include "DocumentGrid.h"


#include "Components/SizeBox.h"

void UDocumentGrid::AddDocument(int32 DocumentIndex, FString DocumentName)
{
	if (!DocumentGrid) return;
	// Create/Add Widget and add it to the vr interface
	UDocumentGridCard* NewWidget = CreateWidget<UDocumentGridCard>(GetWorld(), GridCardClass);
	if (!NewWidget) return;

	NewWidget->SetDocumentName(DocumentName);

	// Get first child of size box and cast it to sizebox
	USizeBox* CardContainer = Cast<USizeBox>(DocumentGrid->GetChildAt(DocumentIndex));

	if (!CardContainer) return;

	CardContainer->AddChild(NewWidget);

}
