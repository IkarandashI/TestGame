// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap/BombTrap.h"
#include "WindTrap.generated.h"

/**
 * 
 */
UCLASS()
class TESTPLATFORMER_API AWindTrap : public ABombTrap
{
	GENERATED_BODY()

public:
	AWindTrap();

protected:
	virtual void OverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void EndOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	void RotateTrap();
	virtual void BeginPlay() override;

	FTimerHandle RotateTrapTimer;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class URadialForceComponent* RadialForce;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class UNiagaraComponent* NiagaraSystem;
};
