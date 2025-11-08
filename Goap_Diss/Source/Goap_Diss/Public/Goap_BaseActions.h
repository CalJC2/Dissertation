// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Goap_BaseActions.generated.h"


// Here to help pass in contoller to the DoActionEvent
class AAIController;

UCLASS(Blueprintable, Abstract)
class GOAP_DISS_API UGoap_BaseActions : public UObject
{
	GENERATED_BODY()	
	
public:	
	UGoap_BaseActions();
	~UGoap_BaseActions();

	//DoAction function, call able event to be used in blueprints (IDE didint like RunAction)
	UFUNCTION(BlueprintImplementableEvent)
	void DoAction(AAIController* Controller);

	//used as the cost of the action
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cost;

	// a map of all conditions needed to run the action
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, bool> Preconditions;

	// a map of all the effects the action wil have on success
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, bool> Effect;

};
