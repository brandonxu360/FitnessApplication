/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: dietlist.cpp
* Date: 3/1/23
* Description: Source file for the DietList class, which is a linked list for storing DietPlan objects.
*			   The list will be used in the project to store 7 DietPlan objects to represent a weekly
*			   exercsie plan.
*/

#include "dietlist.hpp"

//constructor
DietList::DietList() {

	//initialize list to empty
	this->head = NULL;
	this->tail = NULL;
	size = 0;

}

//destructor
DietList::~DietList() {

	//free memory used by all nodes
	DietListNode* curr = head;

	while (head != NULL) { //iterate until end of list

		DietListNode* next = curr->getPNext(); //store next before deleting

		delete curr->getPPlan(); //delete plan inside node
		delete curr; //delete node

		curr = next; //move on to next node
	}

}

//get size of list
int DietList::getSize() {
	return this->size;
}

//get plan from node of specified index
DietPlan* DietList::get(int index) {
	//invalid index inputted
	if (index < 0 || index >= this->size) {
		throw "Invalid index";
	}

	DietListNode* curr = this->head; //iterator node

	for (int i = 0; i < index; i++) { //iterate through list until reach index
		curr = curr->getPNext();
	}

	return curr->getPPlan(); //return plan stored in node
}

//insert node containing plan input at end of list
void DietList::insert(DietPlan* plan) {

	//create new node initialized with the plan
	DietListNode* node = new DietListNode(plan);

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