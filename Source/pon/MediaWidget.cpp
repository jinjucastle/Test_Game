// Fill out your copyright notice in the Description page of Project Settings.


#include "MediaWidget.h"
#include "Components/Image.h"
#include "MediaPlayer.h"
#include "FileMediaSource.h"
void UMediaWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	
	auto MEtail = LoadObject<UMaterialInterface>(NULL,TEXT("/Game/Asset/Movies/Media.Media"), NULL, LOAD_None, NULL);
	IMAGE = Cast<UImage>(GetWidgetFromName("IMAGE"));
	if (IMAGE == nullptr)
		ABLOG_S(Warning);
	IMAGE->SetBrushFromMaterial(MEtail);

	/*UMediaPlayer* player = LoadObject<UMediaPlayer>(NULL, TEXT("/Game/Asset/Movies/TestMedia"), NULL, LOAD_None, NULL);
	if (player == nullptr)
		ABLOG_S(Warning);
	UFileMediaSource* FIEL = LoadObject<UFileMediaSource>(NULL, TEXT("/Game/Asset/Movies/player"), NULL, LOAD_None, NULL);
	if (FIEL == nullptr)
		ABLOG_S(Warning);
	player->OpenSource(FIEL);
	player->Play();
	*/
	
}

bool UMediaWidget::Check()
{
	UMediaPlayer* player = LoadObject<UMediaPlayer>(NULL, TEXT("/Game/Asset/Movies/TestMedia"), NULL, LOAD_None, NULL);
	return player->IsReady();
	
}
