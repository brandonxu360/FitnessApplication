/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: exerciselistnode.hpp
* Date: 3/1/23
* Description: Header file for the ExerciseListNode class, which will serve as the individual nodes in the
*			   ExerciseList linked list. These node are singly, only pointing to the next ExerciseListNode in the list.
*			   Each node will store a pointer to a ExercisePlan object.
*/

#include "header.hpp"
#include "exerciseplan.hpp"

class ExerciseListNode {

public:

	ExerciseListNode(ExercisePlan* plan); //constructor

	~ExerciseListNode(); //destructor

	//getters
	ExerciseListNode* getPNext();
	ExercisePlan* getPPlan();

	//setters
	void setPNext(ExerciseListNode* next);

private:

	ExercisePlan* mPlan; //data
	ExerciseListNode* next; //pointer to next

};