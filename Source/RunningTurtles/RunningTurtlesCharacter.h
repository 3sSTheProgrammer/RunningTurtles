// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunningTurtlesCharacter.generated.h"

class UCameraComponent;

UCLASS()
class RUNNINGTURTLES_API ARunningTurtlesCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// A reference to camera component
	UPROPERTY()
	UCameraComponent* CameraComponent;

	// Character movement speed
	UPROPERTY()
	float MoveAmountPerSecond = 500;

	// Character turn rate
	UPROPERTY()
	float TurnRate = 45.f;
	
public:
	// Sets default values for this character's properties
	ARunningTurtlesCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Used to control character horizontal rotation 
	void LookHorizontally(float Input);

	// Used to control character vertical rotation 
	void LookVertically(float Input);

	// Used to control character forward/backward movement
	void MoveForwardBackward(float Input);

	// Used to control character right/left movement
	void MoveRightLeft(float Input);

	// Called when Interact action is commited
	void Interact();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
