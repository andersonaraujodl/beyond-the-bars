// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/Actor.h"
#include "SCellphone.generated.h"

class UCameraComponent;

UCLASS()
class BEYONDTHEBARS_API ASCellphone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASCellphone();

	void ToggleFlashlight();

	void ToggleCamera();

protected:

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* FlashlightMesh;

	UPROPERTY(EditDefaultsOnly)
	class USpotLightComponent* SpotlightComponent;

	class USceneCaptureComponent2D* SceneCaptureComponent;

	bool isFlashlightOn;
	bool isCameraOn;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

};
