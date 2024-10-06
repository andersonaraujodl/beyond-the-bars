// Fill out your copyright notice in the Description page of Project Settings.


#include "SCellphone.h"

// Sets default values
ASCellphone::ASCellphone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	FlashlightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashlightMeshComponent"));
	RootComponent = FlashlightMesh;

	SpotlightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotlightComponent"));
	SpotlightComponent->SetupAttachment(RootComponent);

	SceneCaptureComponent = FindComponentByClass<USceneCaptureComponent2D>();

	isFlashlightOn = false;
	isCameraOn = false;
}

void ASCellphone::ToggleFlashlight()
{
	SpotlightComponent->SetHiddenInGame(isFlashlightOn);
	isFlashlightOn = !isFlashlightOn;
}

void ASCellphone::ToggleCamera()
{
	SceneCaptureComponent->SetHiddenInGame(isCameraOn);
	isCameraOn = !isCameraOn;
}

// Called when the game starts or when spawned
void ASCellphone::BeginPlay()
{
	Super::BeginPlay();

}