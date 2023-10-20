// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap/BaseTrap.h"
#include "BombTrap.generated.h"

/**
 * 
 */
UCLASS()
class TESTPLATFORMER_API ABombTrap : public ABaseTrap
{
	GENERATED_BODY()

protected:
	virtual void OverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void EndOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	void DamagePlayer();

	UPROPERTY()
	class APlayerCharacter* Player;

	UPROPERTY(EditDefaultsOnly)
	float BombDamage;

	UPROPERTY(EditDefaultsOnly, Category="Material")
	class UMaterialInterface* DefaultMaterial;
	
	UPROPERTY(EditDefaultsOnly, Category="Material")
	class UMaterialInterface* OrangeMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Material")
	class UMaterialInterface* RedMaterial;

	FTimerHandle DamageTimer;
	FTimerHandle ReturnToDefaultTimer;
	FTimerHandle CooldownTimer;

	bool CanActivate = true;
	void ActivateTrapAgain();

	void ReturnDefaultMaterial();
};
