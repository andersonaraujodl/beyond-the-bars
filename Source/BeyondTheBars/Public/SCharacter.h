// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ASCellphone;

UCLASS()
class BEYONDTHEBARS_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	/*UPROPERTY(VisibleAnywhere)
	UHealthComponent* HealthComponent;*/

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASCellphone> CellphoneClass;
	ASCellphone* PlayerPhone;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveSideways(float value);

	void ToggleFlashlight();
	void ToggleCamera();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetCurrentHealth() const;

	void Heal(float healingValue);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float MaxHealth = 100;
	float Health = 0;
};
