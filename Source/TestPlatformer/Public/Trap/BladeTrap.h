// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap/BaseTrap.h"
#include "BladeTrap.generated.h"

/**
 * 
 */
UCLASS()
class TESTPLATFORMER_API ABladeTrap : public ABaseTrap
{
	GENERATED_BODY()
	
protected:
	virtual void OverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
};
