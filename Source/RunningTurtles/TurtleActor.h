// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurtleActor.generated.h"

class USoundBase;

// A enum that describes movement direction options
UENUM()
enum EMoveDirection
{
	Back = -1, // Turtle moves back
	StayStill = 0, // Turtle doesn't move
	UpFront = 1 // Turtle moves forward
		
};

UCLASS()
class RUNNINGTURTLES_API ATurtleActor : public AActor
{
	GENERATED_BODY()

protected:

	// Current movement direction
	UPROPERTY()
	int32 MoveDirection{ EMoveDirection::UpFront };
	
	// Delay before next direction change
	UPROPERTY()
	float ChangeDirectionInterval{ 1.f };

	// The turtle moves towards this point
	UPROPERTY()
	FVector DestinationPoint;
	
	// Direction in which turtle moves in alternative mode
	UPROPERTY(EditAnywhere, Category = "GameProperties")
	int32 AlternativeMoveDirection{ EMoveDirection::UpFront };
	
	// Turtle movement speed
	UPROPERTY(EditAnywhere, Category = "GameProperties")
	int32 MovementSpeed{ 200 };

	// Sounds using by turtle
	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* SpawnSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* WalkSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* DestroySound;

	// Audio component that plays the walking sound
	UPROPERTY()
	UAudioComponent* WalkSoundAudioComponent;
	
	
public:	
	// Sets default values for this actor's properties
	ATurtleActor();

	// Called to set a destination point for turtle
	void SetDestinationPoint(FVector NewDestinationPoint);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to change turtle move pattern
	virtual void ChangeMoveDirection(int32 NewMoveDirection);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
