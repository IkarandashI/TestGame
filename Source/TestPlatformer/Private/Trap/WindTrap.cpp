// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/WindTrap.h"

#include "NiagaraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Player/PlayerCharacter.h"

AWindTrap::AWindTrap()
{
	RadialForce = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForce->SetupAttachment(GetRootComponent());
	RadialForce->SetAutoActivate(false);

	NiagaraSystem = CreateDefaultSubobject<UNiagaraComponent>("NiagaraSystem");
	NiagaraSystem->SetupAttachment(RadialForce);
}

void AWindTrap::BeginPlay()
{
	Super::BeginPlay();

	RotateTrap();
}

void AWindTrap::OverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OverlapPlayer(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
	if (PlayerCharacter)
	{
		RadialForce->Activate();
	}
}

void AWindTrap::EndOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::EndOverlapPlayer(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
	if (PlayerCharacter)
	{
		RadialForce->Deactivate();
	}
}

void AWindTrap::RotateTrap()
{
	const int a= UKismetMathLibrary::RandomIntegerInRange(0,3);
	FVector WindLocation;
	GetWorldTimerManager().SetTimer(RotateTrapTimer, this, &AWindTrap::RotateTrap, 2.f);
	
	switch (a)
	{
	case 0:
		WindLocation = FVector(180.f, 0.f, 100.f);
		RadialForce->SetRelativeLocation(WindLocation);
		NiagaraSystem->SetWorldRotation(FRotator(0.f, -180, 0.f));
		break;
	case 1:
		WindLocation = FVector(-180.f, 0.f, 100.f);
		RadialForce->SetRelativeLocation(WindLocation);
		NiagaraSystem->SetWorldRotation(FRotator(0.f, 0.f, 0.f));
		break;
	case 2:
		WindLocation = FVector(0.f, 180.f, 100.f);
		RadialForce->SetRelativeLocation(WindLocation);
		NiagaraSystem->SetWorldRotation(FRotator(0.f, -90.f, 0.f));
		break;
	case 3:
		WindLocation = FVector(0.f, -180.f, 100.f);
		RadialForce->SetRelativeLocation(WindLocation);
		NiagaraSystem->SetWorldRotation(FRotator(0.f, 90.f, 0.f));
		break;
	}
}


