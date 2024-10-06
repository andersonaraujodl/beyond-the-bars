// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingLight.h"

// Sets default values
AHealingLight::AHealingLight()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	HealingLightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HealingLightMeshComponent"));
	RootComponent = HealingLightMesh;

	PointlightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
	PointlightComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHealingLight::BeginPlay()
{
	Super::BeginPlay();

}


