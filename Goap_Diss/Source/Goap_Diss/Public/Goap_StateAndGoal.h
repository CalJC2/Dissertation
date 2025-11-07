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


USTRUCT(BlueprintType)
struct FWorldState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, bool> WorldState;
};

USTRUCT(BlueprintType)
struct FGoal
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, bool> DesiredState;
};


