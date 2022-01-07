// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

	virtual void Tick(float DeltaTime) override;
	void Fire();
	void HandleDestruction();

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	class USoundBase* DeathSound;
private:
	UPROPERTY(VisibleAnywhere, Category = "Base Pawn Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, Category = "Base Pawn Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, Category = "Base Pawn Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, Category = "Base Pawn Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Fire Settings")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;

protected:	
	void RotateTurret(FVector LookAtTarget);
};
