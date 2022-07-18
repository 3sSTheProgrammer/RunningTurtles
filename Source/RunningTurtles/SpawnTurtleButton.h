// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnTurtleButton.generated.h"

class ATurtleSpawner;

UCLASS()
class RUNNINGTURTLES_API ASpawnTurtleButton : public AActor
{
	GENERATED_BODY()

protected:
	// A number of button that shows which spawner is connected to it
	UPROPERTY(EditAnywhere, Category = ButtonNumber)
	int32 ButtonNumber;
	
	// A reference to TurtleSpawner actor
	UPROPERTY()
	ATurtleSpawner* TurtleSpawner;
	
public:	
	// Sets default values for this actor's properties
	ASpawnTurtleButton();

	// Called to spawn a turtle
	void SpawnTurtle();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to find corresponding turtle spawner on level
	void FindTurtleSpawner();


};
