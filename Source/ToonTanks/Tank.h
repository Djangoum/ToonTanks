// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const { return TankPlayerController; };
	
	bool bAlive = true;

protected:
	virtual void BeginPlay() override;

	void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "TankComponents")
	class USpringArmComponent* ArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "TankComponents")
	class UCameraComponent* CameraComponent; 

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 800.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 90.f;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;
};
