// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurtleActor.h"
#include "TurtleActor2.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGTURTLES_API ATurtleActor2 : public ATurtleActor
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
	virtual void ChangeMoveDirection(int32 NewMoveDirection) override;
};
