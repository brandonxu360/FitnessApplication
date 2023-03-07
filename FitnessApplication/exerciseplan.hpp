/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: exerciseplan.hpp
* Date: 3/1/23
* Description: Header file for the ExercisePlan object, which represents an exercise plan for a single
*			   day with name, goal steps, and date attributes. Also includes overloaded stream operators 
*			   for easier use of ExercisePlan objects.
*/

#pragma once
#include "header.hpp"

class ExercisePlan {

//member functions
public:

	ExercisePlan(); //default constructor
	
	ExercisePlan(ExercisePlan& origPlan); //copy constructor

	~ExercisePlan(); //destructor
	
	//setters
	void setGoalStep(int newGoalStep);
	void setName(std::string newName);
	void setDate(std::string newDate);

	//getters
	std::string getName() const;
	int getGoalStep() const;
	std::string getDate() const;

	//edit
	void editName();
	void editGoal();
	void editDate();

//private attributes
private:
	int mGoalSteps;
	std::string mName;
	std::string mDate;

};

// Overloaded stream insertion operator for displaying an ExercisePlan object
std::ostream& operator<<(std::ostream& os, const ExercisePlan& plan);

// Overloaded stream insertion operator for writing an ExercisePlan object to a file
std::ofstream& operator<<(std::ofstream& ofs, const ExercisePlan& plan);

// Overloaded stream extraction operator for reading an ExercisePlan object from a file
std::ifstream& operator>>(std::ifstream& ifs, ExercisePlan& plan);