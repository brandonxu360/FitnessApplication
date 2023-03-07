/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: dietlist.hpp
* Date: 3/1/23
* Description: Header file for the DietList class, which is a linked list for storing DietPlan objects.
*			   The list will be used in the project to store 7 DietPlan objects to represent a weekly
*			   diet plan.
*/

#include "header.hpp"
#include "dietlistnode.hpp"


class DietList {

public:

	DietList(); //constructor

	~DietList(); //destructor (free memory)

	int getSize(); //get size of list

	DietPlan* get(int index); //return pointer to a dietplan 

	void insert(DietPlan* plan); //insert node with plan input at end of list

//private attributes
private:

	DietListNode* head;
	DietListNode* tail;
	int size;

};