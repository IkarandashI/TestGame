// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/BladeTrap.h"

#include "Kismet/GameplayStatics.h"
#include "Player/PlayerCharacter.h"

void ABladeTrap::OverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OverlapPlayer(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	APlayerCharacter* Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (OtherActor != nullptr && OtherActor == Player)
	{
		TSubclassOf<class UDamageType> DamageTypeClass;
		AController* EventInstigater = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		UGameplayStatics::ApplyDamage(OtherActor, 1.f, EventInstigater, this, DamageTypeClass);
	}
}
