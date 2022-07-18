// Fill out your copyright notice in the Description page of Project Settings.

#include "RunningTurtlesCharacter.h"

#include "SpawnTurtleButton.h"
#include "Camera/CameraComponent.h"
#include "Datasmith/DatasmithCore/Public/DatasmithDefinitions.h"

// Sets default values
ARunningTurtlesCharacter::ARunningTurtlesCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ARunningTurtlesCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Used to control character horizontal rotation 
void ARunningTurtlesCharacter::LookHorizontally(float Input)
{
	AddControllerYawInput(Input * TurnRate * GetWorld()->GetDeltaSeconds());
}

// Used to control character vertical rotation 
void ARunningTurtlesCharacter::LookVertically(float Input)
{
	AddControllerPitchInput(Input * TurnRate * GetWorld()->GetDeltaSeconds());
}

// Used to control character forward/backward movement
void ARunningTurtlesCharacter::MoveForwardBackward(float Input)
{
	AddMovementInput(GetActorForwardVector(), Input);
}

// Used to control character right/left movement
void ARunningTurtlesCharacter::MoveRightLeft(float Input)
{
	AddMovementInput(GetActorRightVector(), Input);
}

// Called when Interact action is commited
void ARunningTurtlesCharacter::Interact()
{
	// Create a line trace
	FVector StartLocation = CameraComponent->GetComponentLocation();
	FVector EndLocation = StartLocation + CameraComponent->GetComponentRotation().Vector() * 250;
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	
	if (GetWorld()->LineTraceSingleByObjectType(HitResult, StartLocation, EndLocation,
		FCollisionObjectQueryParams(), QueryParams))
	{
		// If line trace hit a spawn button - spawn turtle
		if (ASpawnTurtleButton* SpawnTurtleButton = Cast<ASpawnTurtleButton>(HitResult.GetActor()))
		{
			SpawnTurtleButton->SpawnTurtle();		
		}
	}
}

// Called every frame
void ARunningTurtlesCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARunningTurtlesCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForwardBackward"), this, &ARunningTurtlesCharacter::MoveForwardBackward);
	PlayerInputComponent->BindAxis(TEXT("MoveRightLeft"), this, &ARunningTurtlesCharacter::MoveRightLeft);
	PlayerInputComponent->BindAxis(TEXT("LookHorizontally"), this, &ARunningTurtlesCharacter::LookHorizontally);
	PlayerInputComponent->BindAxis(TEXT("LookVertically"), this, &ARunningTurtlesCharacter::LookVertically);

	PlayerInputComponent->BindAction(TEXT("Interact"), EInputEvent::IE_Pressed, this,
		&ARunningTurtlesCharacter::Interact);
}

