// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/BaseTrap.h"

#include "Components/BoxComponent.h"

ABaseTrap::ABaseTrap()
{
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	SetRootComponent(Box);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(GetRootComponent());
}

void ABaseTrap::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &ABaseTrap::OverlapPlayer);
	Box->OnComponentEndOverlap.AddDynamic(this, &ABaseTrap::EndOverlapPlayer);
	Box->OnComponentHit.AddDynamic(this, &ABaseTrap::HitPlayer);
}

void ABaseTrap::OverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABaseTrap::EndOverlapPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ABaseTrap::HitPlayer(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
}
