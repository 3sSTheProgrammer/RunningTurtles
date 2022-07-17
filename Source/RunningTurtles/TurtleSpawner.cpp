// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleSpawner.h"

#include "TurtleActor.h"

// Sets default values
ATurtleSpawner::ATurtleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

int32 ATurtleSpawner::GetSpawnerNumber()
{
	return SpawnerNumber;
}

// Called when the game starts or when spawned
void ATurtleSpawner::BeginPlay()
{
	Super::BeginPlay();

	DestinationPoint = GetActorLocation() + GetActorForwardVector() * 1500;
}

void ATurtleSpawner::SpawnTurtle()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning turtle"));
	ATurtleActor* SpawnedTurtleActor = GetWorld()->SpawnActor<ATurtleActor>(TurtleActor,
		GetActorLocation(), GetActorRotation());
	SpawnedTurtleActor->SetDestinationPoint(DestinationPoint);
}

