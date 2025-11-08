// Fill out your copyright notice in the Description page of Project Settings.


#include "Goap_Planner.h"
#include "Goap_BaseActions.h"

bool UGoap_Planner::FindPlan(FWorldState CurrentState, FGoal Goal, TArray<UGoap_BaseActions*> AvailableActions, TQueue<UGoap_BaseActions*> OutPlan)
{
    // a list to the check what needs to be done still
    TArray<FGoapNodes*> ToDoList;
    // a list of states already checked
    TSet<FWorldState> DoneList;

    // a starting node
    float StartEstimate = CalculateEstimateCost(CurrentState, Goal);
    FGoapNodes* StartNode = new FGoapNodes(CurrentState, nullptr, nullptr, 0.0f, StartEstimate);
    ToDoList.Add(StartNode);

    //The planning algorithm
    while(ToDoList.Num() > 0)
    {
        //Loops through the ToDoList and find the one with the lowest cost
        FGoapNodes* CurrentNode = ToDoList[0];
        int32 CurrentIndex = 0;
        for (int32 i = 1; i < ToDoList.Num(); ++i)
        {
            if(ToDoList[i]->GetCost() < CurrentNode->GetCost())
            {
                CurrentNode = ToDoList[i];
                CurrentIndex = i;
            }
        }

        //Check to see if the current state achieves the goal
        if(DoesStateAchieveGoal(CurrentNode->State, Goal))
        {
            //reconstruct the plan
            ReconstructPlan(CurrentNode, OutPlan);
            //delete all nodes created to do the checks
            for(FGoapNodes* Node : ToDoList) {delete Node; }
            //returns find plan to be true
            return true;
        }

        //move current node check from todolist to done list
        ToDoList.RemoveAt(CurrentIndex);
        DoneList.Add(CurrentNode->State);

        //Check every actions to see if it can be run with the current world state

 
    }


    return false;
}

void UGoap_Planner::ReconstructPlan(FGoapNodes* GoalNode, TQueue<UGoap_BaseActions*>& OutPlan)
{
}

float UGoap_Planner::CalculateEstimateCost(const FWorldState& State, FGoal& Goal)
{
    return 0.0f;
}

bool UGoap_Planner::DoesStateAchieveGoal(const FWorldState& State, FGoal &Goal)
{
    return false;
}

bool UGoap_Planner::ArePreconditionsMet(const FWorldState& State, UGoap_BaseActions& Action)
{
    return false;
}

FWorldState UGoap_Planner::ApplyEffects(const FWorldState& State, UGoap_BaseActions& Action)
{
    return FWorldState();
}
