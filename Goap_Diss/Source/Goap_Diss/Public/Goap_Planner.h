// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Goap_StateAndGoal.h"
#include "Goap_Planner.generated.h"

/**
 * The Main part of the GOAP system. contains all logic for finding the plan
 */

class UGoap_BaseActions;


UCLASS()
class GOAP_DISS_API UGoap_Planner : public UObject
{
	GENERATED_BODY()
public:

	//The planning algorithm itself. tries to fine the best sequence of actions to satisfy the goal
	bool FindPlan(
		FWorldState CurrentState, 
		FGoal Goal, 
		TArray<UGoap_BaseActions*> AvailableActions, 
		TQueue<UGoap_BaseActions*> OutPlan
	);

private:

	// Struct for the planning algorithm to use. contains all information required for the planner to make descisions
	struct FGoapNodes
	{
		FWorldState State;
		FGoapNodes* Parent = nullptr;
		UGoap_BaseActions* Action = nullptr;
		float GoapCost;
		float EstimatedCost;

		FGoapNodes(const FWorldState& _State, FGoapNodes* _Parent, UGoap_BaseActions* _Action, float _GoapCost, float _EstimatedCost)
			: State(_State), Parent(_Parent), Action(_Action), GoapCost(_GoapCost), EstimatedCost(_EstimatedCost) {}

		float GetCost() const {return GoapCost + EstimatedCost; }
	};	

	//reconstructs the plan by working backwards from the goal
	void ReconstructPlan(FGoapNodes* GoalNode, TQueue<UGoap_BaseActions*>& OutPlan);

	//Estimates the cost from a state to the goal
	float CalculateEstimateCost(const FWorldState& State, FGoal& Goal);

	//Checks if the goals conditions have been met
	bool DoesStateAchieveGoal(const FWorldState& State, FGoal& Goal);

	//checks that all preconditions of an action have been met with the world state
	bool ArePreconditionsMet(const FWorldState& State, UGoap_BaseActions& Action);

	//applies the actions effect to the current state
	FWorldState ApplyEffects(const FWorldState& State, UGoap_BaseActions& Action);
};