// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassDrill.h"

FString ASBuildingClassDrill::IL_BuildingTitle = "buildDes_name_121";
TMap<int32, FBuildingLvlDataDrill> ASBuildingClassDrill::LvlData;

ASBuildingClassDrill::ASBuildingClassDrill() {


	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassDrill::OnClicked);
	
	
	BtnCompArena   = BtnListComp.Add(EBuildingBtnAction::BBA_ARENA, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompArena")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDetail  = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));



	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompArena->SetupAttachment(RootComponent);
	
}




void ASBuildingClassDrill::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/jiaochang.jiaochang'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassDrill::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}

void ASBuildingClassDrill::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassDrill::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassDrill::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassDrill::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompArena->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassDrill::OnBtnClickedArena);


}


void ASBuildingClassDrill::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassDrill::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassDrill::OnBtnClickedArena() {
	GLog->Log(__FUNCTION__);
}




void ASBuildingClassDrill::setBuildingActionBtnList() {

}
void ASBuildingClassDrill::initBuilding() {

}


void ASBuildingClassDrill::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataDrill BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}