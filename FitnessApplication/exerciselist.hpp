/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: exerciselist.hpp
* Date: 3/1/23
* Description: Header file for the ExerciseList class, which is a linked list for storing ExercisePlan objects.
*			   The list will be used in the project to store 7 ExercisePlan objects to represent a weekly 
*			   exercise plan.
*/

#include "header.hpp"
#include "exerciselistnode.hpp"


class ExerciseList {

public:

	ExerciseList(); //constructor

	~ExerciseList(); //destructor (free memory)

	int getSize(); //get size of list

	ExercisePlan* get(int index); //return pointer to a dietplan 

	void insert(ExercisePlan* plan); //insert node with plan input at end of list

//private attributes
private:

	ExerciseListNode* head;
	ExerciseListNode* tail;
	int size;

};