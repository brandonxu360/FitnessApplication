/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: dietlistnode.cpp
* Date: 3/1/23
* Description: Source file that holds all function and constructor definitions for the DietListNode class,
*			   which will serve as the individual nodes in the DietList linked list. These node are singly,
*			   only pointing to the next DietListNode in the list. Each node will store a pointer to a 
*			   DietPlan object.
*/

#include "dietlistnode.hpp"

//default constructor
DietListNode::DietListNode(DietPlan* plan) {

	//initialize values
	this->mPlan = plan;
	this->next = NULL;

}

//destructor
DietListNode::~DietListNode() {
	delete this->mPlan; //delete plan when node is destructed
}

//get pointer to next node
DietListNode* DietListNode::getPNext() {
	return next;
}

//get pointer to plan
DietPlan* DietListNode::getPPlan() {
	return mPlan;
}

//set pointer to next node to next input
void DietListNode::setPNext(DietListNode* next) {
	this->next = next;
}