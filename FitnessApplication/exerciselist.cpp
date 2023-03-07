/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: exerciselist.cpp
* Date: 3/1/23
* Description: Source file that holds all function and constructor definitions for the ExerciseList class, 
*			   which is a linked list for storing ExercisePlan objects. The list will be used in the project
*			   to store 7 ExercisePlan objects to represent a weekly exercsie plan.
*/

#include "exerciselist.hpp"

//constructor
ExerciseList::ExerciseList() {

	//initialize list to empty
	this->head = NULL;
	this->tail = NULL;
	size = 0;

}

//destructor
ExerciseList::~ExerciseList() {

	//free memory used by all nodes
	ExerciseListNode* curr = head;

	while (head != NULL) { //iterate through list until end

		ExerciseListNode* next = curr->getPNext(); //store next before deleting

		delete curr->getPPlan();
		delete curr;

		curr = next; //move on to next node
	}

}

//get size
int ExerciseList::getSize() {
	return this->size;
}

//get plan from node of specified index
ExercisePlan* ExerciseList::get(int index) {
	//invalid index inputted
	if (index < 0 || index >= this->size) {
		throw "Invalid index";
	}

	ExerciseListNode* curr = this->head; //iterator node

	for (int i = 0; i < index; i++) { //iterate through list until reach index
		curr = curr->getPNext();
	}

	return curr->getPPlan(); //return plan stored in node
}

//insert node containing plan input at end of list
void ExerciseList::insert(ExercisePlan* plan) {

	//create new node initialized with the plan
	ExerciseListNode* node = new ExerciseListNode(plan);

	if (this->head == nullptr) { //if list is empty
		this->head = node;
		this->tail = node;
	}

	else { //set node as tail
		this->tail->setPNext(node);
		this->tail = node;
	}

	this->size++;
}