#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Drone.generated.h"


// Forward declarations are preferred to including headers in UE.
class UStaticMeshComponent;
class UFloatingPawnMovement;
class UCameraComponent;
class USpringArmComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

struct FInputActionValue;


UCLASS()
class EXAIL_API ADrone : public APawn
{
	GENERATED_BODY()

public:

	ADrone();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:

	virtual void BeginPlay() override;


private:

	UPROPERTY(EditAnywhere)
	float LookSpeed = 1.f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DroneMesh;

	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* Movement;


	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;


	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DroneMappingContext;


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};