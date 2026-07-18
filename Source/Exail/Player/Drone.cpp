// Fill out your copyright notice in the Description page of Project Settings.


#include "Drone.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include <Math/MathFwd.h>
#include "InputActionValue.h"
#include <Templates/Casts.h>
#include "EnhancedInputComponent.h"
#include <InputTriggers.h>
#include <Engine/LocalPlayer.h>
#include <GameFramework/PlayerController.h>
#include "EnhancedInputSubsystems.h"
#include <Engine/EngineTypes.h>
#include <Math/UnrealMathUtility.h>

// Sets default values
ADrone::ADrone()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	DroneMesh = CreateDefaultSubobject<UStaticMeshComponent>("DroneMesh");
	RootComponent = DroneMesh;

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");

	SpringArm->SetupAttachment(DroneMesh);
	SpringArm->TargetArmLength = 500.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 5.f;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DroneMappingContext, 0);
		}
	}
}

void ADrone::Move(const FInputActionValue& Value)
{
	FVector MovementVector = Value.Get<FVector>();

	FVector Forward = Camera->GetForwardVector();
	FVector Right = Camera->GetRightVector();

	AddMovementInput(Forward, MovementVector.X);
	AddMovementInput(Right, MovementVector.Y);
	AddMovementInput(FVector::UpVector, MovementVector.Z);
}

void ADrone::Look(const FInputActionValue& Value)
{
	FVector2D LookAxis = Value.Get<FVector2D>();
	FRotator Rotation = SpringArm->GetRelativeRotation();

	Rotation.Pitch += -LookAxis.Y;
	Rotation.Yaw += LookAxis.X;

	Rotation.Pitch = FMath::Clamp(Rotation.Pitch, -80.f, 80.f);

	SpringArm->SetRelativeRotation(Rotation);
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADrone::Move);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADrone::Look);
	}
}

