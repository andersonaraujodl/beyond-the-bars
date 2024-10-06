// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SCellphone.h"

// Sets default values
ASCharacter::ASCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Heal(MaxHealth);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCurrentHealth();

	if (CellphoneClass)
	{
		PlayerPhone = GetWorld()->SpawnActor<ASCellphone>(CellphoneClass);

		if (PlayerPhone)
		{
			//Attach Cellphone
			PlayerPhone->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("hand_r_phone_socket"));
		}
	}
}


void ASCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ASCharacter::MoveSideways(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void ASCharacter::ToggleFlashlight()
{
	PlayerPhone->ToggleFlashlight();
}

void ASCharacter::ToggleCamera()
{
	UE_LOG(LogTemp, Warning, TEXT("Toggle Camera"));
	PlayerPhone->ToggleCamera();
}

float ASCharacter::GetCurrentHealth() const
{
	return Health;
}

void ASCharacter::Heal(float const healingValue)
{
	UE_LOG(LogTemp, Warning, TEXT("Healing: %f"), healingValue);

	float NewHealth = GetCurrentHealth() + healingValue;
	Health = FMath::Clamp(NewHealth, 0.f, MaxHealth);
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveSideways", this, &ASCharacter::MoveSideways);

	PlayerInputComponent->BindAxis("TurnYall", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnPitch", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("ToggleFlashlight", IE_Pressed, this, &ASCharacter::ToggleFlashlight);
	PlayerInputComponent->BindAction("ToggleCamera", IE_Pressed, this, &ASCharacter::ToggleCamera);

}