// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Goap_StateAndGoal.generated.h"


/**
 * 
 */
class GOAP_DISS_API Goap_StateAndGoal
{
public:
	Goap_StateAndGoal();
	~Goap_StateAndGoal();


};

// a struct contatining the functionality to hold the current world state the AI needs to know
USTRUCT(BlueprintType)
struct FWorldState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, bool> WorldState;
};

// a struct containing the goal states and the priority of the goals
USTRUCT(BlueprintType)
struct FGoal
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, bool> DesiredState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Priority;
};


