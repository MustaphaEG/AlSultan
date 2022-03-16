// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassStable.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassStable : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;

	ASBuildingClassStable();

	UPaperFlipbookComponent* TrainCamel1;
	UPaperFlipbookComponent* TrainCamel2;
	UPaperFlipbookComponent* TrainCamel3;
	UPaperFlipbookComponent* TrainCamel4;


	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void showTrainSol();
	void hideTrainSol();

	void setStableCamels();
	void setBuildingActionBtnList() override;
	void initBuilding() override;
};
