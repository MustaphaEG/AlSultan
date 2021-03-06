// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassOFarm.h"


FString ASBuildingClassOFarm::IL_BuildingTitle = "buildDes_name_201";
TMap<int32, FBuildingLvlDataFarm> ASBuildingClassOFarm::LvlData;

ASBuildingClassOFarm::ASBuildingClassOFarm(){

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassOFarm::OnClicked);

	BtnCompCollect  = BtnListComp.Add(EBuildingBtnAction::BBA_COLLECT_Fod, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompCollect")));
	BtnCompUpgrade  = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDetail   = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));
	BtnCompGoldAcce = BtnListComp.Add(EBuildingBtnAction::BBA_BOOST, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompGoldAcce")));
	BtnCompItemAcce = BtnListComp.Add(EBuildingBtnAction::BBA_RES_Acc_Fod, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompItemAcce")));

	BtnCompCollect ->SetupAttachment(RootComponent);
	BtnCompUpgrade ->SetupAttachment(RootComponent);
	BtnCompDetail  ->SetupAttachment(RootComponent);
	BtnCompGoldAcce->SetupAttachment(RootComponent);
	BtnCompItemAcce->SetupAttachment(RootComponent);
}

void ASBuildingClassOFarm::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT(""));
	Sprite->SetSprite(BuildingSprite);

}

void ASBuildingClassOFarm::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassOFarm::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompItemAcce->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOFarm::OnBtnClickedItemAcce);

	T = Cast<USWid_BuildingACBtn>(BtnCompGoldAcce->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOFarm::OnBtnClickedGoldAcce);

	T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOFarm::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOFarm::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompCollect->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOFarm::OnBtnClickedCollect);

}

void ASBuildingClassOFarm::OnBtnClickedItemAcce() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOFarm::OnBtnClickedGoldAcce() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOFarm::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOFarm::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOFarm::OnBtnClickedCollect() {
	GLog->Log(__FUNCTION__);
}



void ASBuildingClassOFarm::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassOFarm::setBuildingActionBtnList() {

}

void ASBuildingClassOFarm::initBuilding() {
	
}

void ASBuildingClassOFarm::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataFarm BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}