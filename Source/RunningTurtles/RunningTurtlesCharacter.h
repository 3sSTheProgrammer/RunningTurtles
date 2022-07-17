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
	UPROPERTY()
	UCameraComponent* CameraComponent;

	UPROPERTY()
	float MoveAmountPerSecond = 500;

	UPROPERTY()
	float TurnRate = 45.f;
	
public:
	// Sets default values for this character's properties
	ARunningTurtlesCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void LookHorizontally(float Input);

	void LookVertically(float Input);

	void MoveForwardBackward(float Input);

	void MoveRightLeft(float Input);

	void Interact();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
