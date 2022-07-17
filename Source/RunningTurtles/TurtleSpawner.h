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
	UPROPERTY(EditAnywhere, Category = "GameProperties")
	int32 SpawnerNumber;

	UPROPERTY(EditAnywhere, Category = "GameProperties")
	TSubclassOf<ATurtleActor> TurtleActor;

	UPROPERTY()
	FVector DestinationPoint;
public:	
	// Sets default values for this actor's properties
	ATurtleSpawner();

	int32 GetSpawnerNumber();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void SpawnTurtle();
};
