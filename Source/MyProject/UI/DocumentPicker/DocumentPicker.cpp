// Fill out your copyright notice in the Description page of Project Settings.


#include "DocumentPicker.h"
#include "../../Saving/UICreatorSaveGameIndex.h"
#include "ActionBar.h"
#include "DocumentGrid.h"


// Sets default values
ADocumentPicker::ADocumentPicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	DocumentGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("DocumentGrid"));
	DocumentGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ADocumentPicker::BeginPlay()
{
	Super::BeginPlay();

	// Grab docment grid widget, cast it to document grid and add it as child
	UDocumentGrid* DocumentGridWidget = Cast<UDocumentGrid>(DocumentGrid->GetUserWidgetObject());
	if (!DocumentGrid) return;


	UActionBar* ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (!DocumentGrid) return;
	
	
	int32 Index = 0;
	for (FString SlotName : UUICreatorSaveGameIndex::Load()->GetSlotNames())
	{
		DocumentGridWidget->AddDocument(Index, SlotName);
		++Index;
	}
}


