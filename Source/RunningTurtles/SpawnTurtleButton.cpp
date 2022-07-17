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

void ASpawnTurtleButton::FindTurtleSpawner()
{
	TArray<AActor*> TurtleSpawners;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATurtleSpawner::StaticClass(), TurtleSpawners);
	//UE_LOG(LogTemp, Warning, TEXT("Found %d spawners"), TurtleSpawners.Num());
	for (AActor* FoundActor :TurtleSpawners)
	{
		if (ATurtleSpawner* FoundTurtleSpawner = Cast<ATurtleSpawner>(FoundActor))
		{
			if (FoundTurtleSpawner->GetSpawnerNumber() == ButtonNumber)
			{
				TurtleSpawner = FoundTurtleSpawner;
			}
		}
	}
}


