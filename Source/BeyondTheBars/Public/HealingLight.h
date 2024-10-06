// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "HealingLight.generated.h"

UCLASS()
class BEYONDTHEBARS_API AHealingLight : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealingLight();

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* HealingLightMesh;

	UPROPERTY(EditDefaultsOnly)
	class UPointLightComponent* PointlightComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:


};
