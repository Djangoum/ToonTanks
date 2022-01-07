// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Fire Settings")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Fire Settings")
	class UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Fire Settings")
	float InitialSpeed = 1300.f;

	UPROPERTY(EditDefaultsOnly, Category = "Fire Settings")
	float MaxSpeed = 2000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Fire Settings")
	float Damage = 15.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	class UParticleSystemComponent* SmokeTrailParticlesComponent;

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	class USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Fire Settings")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};
