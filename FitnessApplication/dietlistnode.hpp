/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: dietlistnode.hpp
* Date: 3/1/23
* Description: Header file for the DietListNode class, which will serve as the individual nodes in the 
*			   DietList linked list. These node are singly, only pointing to the next DietListNode in the list.
*			   Each node will store a pointer to a DietPlan object.
*/

#include "header.hpp"
#include "dietplan.hpp"

class DietListNode {

public:

	DietListNode(DietPlan* plan); //constructor

	~DietListNode(); //destructor

	//getters
	DietListNode* getPNext();
	DietPlan* getPPlan();

	//setters
	void setPNext(DietListNode* next);

private:

	DietPlan* mPlan; //data
	DietListNode* next; //pointer to next
	
};