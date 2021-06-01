#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "DocumentGridCard.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UDocumentGridCard : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetDocumentName(FString DocumentName);
	
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget));
	UTextBlock* SlotName;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget));
	UButton* CardButton;

private:
	UFUNCTION()
	void CardButtonClicked();

	FString DocumentName;
};
