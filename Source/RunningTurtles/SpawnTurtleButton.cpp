// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnTurtleButton.h"
#include "TurtleSpawner.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpawnTurtleButton::ASpawnTurtleButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called to spawn a turtle
void ASpawnTurtleButton::SpawnTurtle()
{
	if (TurtleSpawner)
	{
		TurtleSpawner->SpawnTurtle();
	}
}

// Called when the game starts or when spawned
void ASpawnTurtleButton::BeginPlay()
{
	Super::BeginPlay();

	FindTurtleSpawner();
}

// Called to find corresponding turtle spawner on level
void ASpawnTurtleButton::FindTurtleSpawner()
{
	TArray<AActor*> TurtleSpawners;
	
	// Find all turtle spawners 
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATurtleSpawner::StaticClass(), TurtleSpawners);
	for (AActor* FoundActor :TurtleSpawners)
	{
		if (ATurtleSpawner* FoundTurtleSpawner = Cast<ATurtleSpawner>(FoundActor))
		{
			// if turtle spawner number is the same as this button's number
			if (FoundTurtleSpawner->GetSpawnerNumber() == ButtonNumber)
			{
				// Set TurtleSpawner to found spawner
				TurtleSpawner = FoundTurtleSpawner;
			}
		}
	}
}


