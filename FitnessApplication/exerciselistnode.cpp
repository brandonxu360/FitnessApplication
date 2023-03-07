/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: exerciselistnode.cpp
* Date: 3/1/23
* Description: Source file that holds all function and constructor definitions for the ExerciseListNode class,
*			   which will serve as the individual nodes in the ExerciseList linked list. These node are singly,
*			   only pointing to the next ExerciseListNode in the list. Each node will store a pointer to a
*			   ExercisePlan object.
*/

#include "exerciselistnode.hpp"

//default constructor
ExerciseListNode::ExerciseListNode(ExercisePlan* plan) {

	//initialize values
	this->mPlan = plan;
	this->next = NULL;

}

//destructor
ExerciseListNode::~ExerciseListNode() {
	delete this->mPlan;
}

//get pointer to next node
ExerciseListNode* ExerciseListNode::getPNext() {
	return next;
}

//get pointer to plan
ExercisePlan* ExerciseListNode::getPPlan() {
	return mPlan;
}

//set pointer to next node
void ExerciseListNode::setPNext(ExerciseListNode* next) {
	this->next = next;
}