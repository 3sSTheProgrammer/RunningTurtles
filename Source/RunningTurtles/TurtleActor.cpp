// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleActor.h"

#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
ATurtleActor::ATurtleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called to set a destination point for turtle
void ATurtleActor::SetDestinationPoint(FVector NewDestinationPoint)
{
	DestinationPoint = NewDestinationPoint; 
}

// Called when the game starts or when spawned
void ATurtleActor::BeginPlay()
{
	Super::BeginPlay();

	// Set timer for move direction change
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &ATurtleActor::ChangeMoveDirection, AlternativeMoveDirection);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, ChangeDirectionInterval, false);
	
	// Play spawn sound
	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), SpawnSound, GetActorLocation(), GetActorRotation());
	
	// Create walking sound
	WalkSoundAudioComponent = UGameplayStatics::SpawnSoundAttached(WalkSound, GetRootComponent());

	// Create a spawn visual effect
	UNiagaraFunctionLibrary::SpawnSystemAttached(WalkEffect, GetRootComponent(), TEXT("Walk Effect"), GetActorLocation(), GetActorRotation(), 
		EAttachLocation::KeepWorldPosition, true);

	// Create a spawn visual effect
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), SpawnEffect, GetActorLocation());
}

// Called to change turtle move pattern
void ATurtleActor::ChangeMoveDirection(int32 NewMoveDirection)
{
	// Change direction
	MoveDirection = NewMoveDirection;

	FRotator CurrentRotation = GetActorRotation();
	
	// Adjust move direction with rotation
	if (MoveDirection == EMoveDirection::UpFront)
	{
		if (CurrentRotation.Yaw != 90.f)
		{
			CurrentRotation.Yaw = 90.f;
			SetActorRotation(CurrentRotation);
		}
	}
	else if (MoveDirection == EMoveDirection::Back)
	{
		CurrentRotation.Yaw = -90.f;
		SetActorRotation(CurrentRotation);
	}
	
	// Choose direction and timer duration for next direction change 
	if (ChangeDirectionInterval == 1.f)
	{
		ChangeDirectionInterval = 0.5;
		NewMoveDirection = EMoveDirection::UpFront;
	}
	else if (ChangeDirectionInterval == 0.5)
	{
		ChangeDirectionInterval = 1.f;
		NewMoveDirection = AlternativeMoveDirection;
	}

	// Set timer for next direction change
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &ATurtleActor::ChangeMoveDirection, NewMoveDirection);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, ChangeDirectionInterval, false);
	
}

// Called every frame
void ATurtleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Calculate new location depending on move direction and destination point
	FVector VectorToDestinationPoint = DestinationPoint - GetActorLocation();
	VectorToDestinationPoint.Normalize();
	FVector NewLocation = GetActorLocation() + VectorToDestinationPoint * MoveDirection * MovementSpeed * DeltaTime;

	// Check if reached destination point
	if (NewLocation.Y > DestinationPoint.Y)
	{
		
		// Stop walking sound
		WalkSoundAudioComponent->Stop();

		// Play death sound
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), DestroySound, GetActorLocation(), GetActorRotation());
		
		// Create a destroy visual effect
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), DestroyEffect, GetActorLocation());

		// Destroy self
		Destroy();
	}
	else
	{
		// Move to new location
		SetActorLocation(NewLocation);
	}
	
}

