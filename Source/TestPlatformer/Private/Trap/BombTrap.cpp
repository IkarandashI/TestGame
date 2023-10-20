// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/BombTrap.h"

#include "Kismet/GameplayStatics.h"
#include "Player/PlayerCharacter.h"

void ABombTrap::OverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OverlapPlayer(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (OrangeMaterial == nullptr) return;
	Player = Cast<APlayerCharacter>(OtherActor);
	if (Player && CanActivate == true)
	{
		GetWorldTimerManager().SetTimer(DamageTimer, this, &ABombTrap::DamagePlayer, 1.f);
		StaticMesh->SetMaterial(0, OrangeMaterial);
	}
}

void ABombTrap::EndOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::EndOverlapPlayer(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
	if (PlayerCharacter)
	{
		Player = nullptr;
	}
}

void ABombTrap::DamagePlayer()
{
	if (RedMaterial == nullptr) return;
	
	StaticMesh->SetMaterial(0, RedMaterial);
	AController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (Player != nullptr)
	{
		TSubclassOf<UDamageType> DamageType;
		UGameplayStatics::ApplyDamage(Player, BombDamage, PlayerController, this, DamageType);
	}
	GetWorldTimerManager().SetTimer(DamageTimer, this, &ABombTrap::ActivateTrapAgain, 5.f);
	GetWorldTimerManager().SetTimer(ReturnToDefaultTimer, this, &ABombTrap::ReturnDefaultMaterial, 0.3f);
	CanActivate = false;
}

void ABombTrap::ActivateTrapAgain()
{
	CanActivate = true;
}

void ABombTrap::ReturnDefaultMaterial()
{
	if (DefaultMaterial == nullptr) return;
	StaticMesh->SetMaterial(0, DefaultMaterial);
}
