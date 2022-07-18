// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleSpawner.h"

#include "TurtleActor.h"

// Sets default values
ATurtleSpawner::ATurtleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// A getter for SpawnNumber
int32 ATurtleSpawner::GetSpawnerNumber()
{
	return SpawnerNumber;
}

// Called when the game starts or when spawned
void ATurtleSpawner::BeginPlay()
{
	Super::BeginPlay();

	// Generate spawn point and turtle destination point depending on spawner position
	SpawnPoint = GetActorLocation() + GetActorForwardVector() * 200;
	DestinationPoint = GetActorLocation() + GetActorForwardVector() * 1700;
}

// Called to spawn a turtle
void ATurtleSpawner::SpawnTurtle()
{
	ATurtleActor* SpawnedTurtleActor = GetWorld()->SpawnActor<ATurtleActor>(TurtleActor,
		SpawnPoint, GetActorRotation());
	SpawnedTurtleActor->SetDestinationPoint(DestinationPoint);
}

