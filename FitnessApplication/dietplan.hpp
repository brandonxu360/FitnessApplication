/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: dietplan.hpp
* Date: 3/1/23
* Description: Header file for the DietPlan object, which represents an diet plan for a single
*			   day with name, goal calories, and date attributes. Also includes overloaded stream operators
*			   for easier use of DietPlan objects.
*/

#pragma once
#include "header.hpp"

class DietPlan {

public:

	DietPlan(); //default constructor

	DietPlan(DietPlan& origPlan); //copy constructor

	~DietPlan(); //destructor

	//setters
	void setGoalCal(int newGoalCal);
	void setName(std::string newName);
	void setDate(std::string newDate);

	//getters
	std::string getName() const;
	int getGoalCalories() const;
	std::string getDate() const;

	//edit
	void editName();
	void editGoal();
	void editDate();

//private attributes
private:

	int mGoalCal;
	std::string mName;
	std::string mDate;

};

// Overloaded stream insertion operator for displaying a DietPlan object
std::ostream& operator<<(std::ostream& os, const DietPlan& plan);

// Overloaded stream insertion operator for writing a DietPlan object to a file
std::ofstream& operator<<(std::ofstream& ofs, const DietPlan& plan);

// Overloaded stream extraction operator for reading a DietPlan object from a file
std::fstream& operator>>(std::fstream& ifs, DietPlan& plan);