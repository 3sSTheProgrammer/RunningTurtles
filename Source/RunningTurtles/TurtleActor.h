// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurtleActor.generated.h"

UENUM()
enum EMoveDirection
{
	Back = -1,
	StayStill = 0,
	UpFront = 1
		
};

UCLASS()
class RUNNINGTURTLES_API ATurtleActor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 MoveDirection{ EMoveDirection::UpFront };
	
	UPROPERTY()
	float ChangeDirectionInterval{ 1.f };

	UPROPERTY()
	FVector DestinationPoint;
	
	UPROPERTY(EditAnywhere, Category = "GameProperties")
	int32 AlternativeMoveDirection{ EMoveDirection::UpFront };
	
	UPROPERTY(EditAnywhere, Category = "GameProperties")
	int32 MovementSpeed{ 200 };

	UPROPERTY(EditAnywhere, Category = "GameProperties")
	int32 MaxY{ 1000 };
	
	
public:	
	// Sets default values for this actor's properties
	ATurtleActor();

	void SetDestinationPoint(FVector NewDestinationPoint);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void ChangeMoveDirection(int32 NewMoveDirection);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
