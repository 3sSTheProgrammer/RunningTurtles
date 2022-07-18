// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurtleSpawner.generated.h"

class ATurtleActor;

UCLASS()
class RUNNINGTURTLES_API ATurtleSpawner : public AActor
{
	GENERATED_BODY()

protected:
	// Defines which type of turtle is spawned by this spawner
	UPROPERTY(EditAnywhere, Category = "GameProperties")
	int32 SpawnerNumber;

	// A reference for turtle actor
	UPROPERTY(EditAnywhere, Category = "GameProperties")
	TSubclassOf<ATurtleActor> TurtleActor;

	// Turtle spawn point
	UPROPERTY()
	FVector SpawnPoint;

	// Turtle destination point
	UPROPERTY()
	FVector DestinationPoint;

public:	
	// Sets default values for this actor's properties
	ATurtleSpawner();

	// A getter for SpawnNumber
	int32 GetSpawnerNumber();

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Called to spawn a turtle
	void SpawnTurtle();
};
