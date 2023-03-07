/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: exerciseplan.cpp
* Date: 3/1/23
* Description: Source file for the ExercisePlan object, which represents an exercise plan for a single
*			   day with name, goal steps, and date attributes. Also includes overloaded stream operators
*			   for easier use of ExercisePlan objects.
*/

#include "exerciseplan.hpp"

//default constructor
ExercisePlan::ExercisePlan() {

	//set attributes to default values
	mGoalSteps = 0;
	mName = "";
	mDate = "";

}

//copy constructor
ExercisePlan::ExercisePlan(ExercisePlan& origPlan) {

	//copy values over
	mGoalSteps = origPlan.mGoalSteps;
	mName = origPlan.mName;
	mDate = origPlan.mDate;

}

//destructor
ExercisePlan::~ExercisePlan() {

}

//setter functions
void ExercisePlan::setGoalStep(int newGoalStep) {
	mGoalSteps = newGoalStep;
}

void ExercisePlan::setName(std::string newName) {
	mName = newName;
}

void ExercisePlan::setDate(std::string newDate) {
	mDate = newDate;
}

//getter functions
std::string ExercisePlan::getName() const {
	return mName;
}

int ExercisePlan::getGoalStep() const {
	return mGoalSteps;
}

std::string ExercisePlan::getDate() const {
	return mDate;
}

//edit functions - get user input and set field accordingly
void ExercisePlan::editName() {
	std::string name;
	std::cout << "current name: " << getName() << std::endl;
	std::cout << "New name: ";
	std::cin >> name;
	std::cout << std::endl << "Name set to: " << name << std::endl;
	setName(name);
}

void ExercisePlan::editGoal() {
	int goal;
	std::cout << "current goal: " << getGoalStep() << "steps" << std::endl;
	std::cout << "New goal: ";
	std::cin >> goal;
	std::cout << std::endl << "Goal set to " << goal << " steps" << std::endl;
	setGoalStep(goal);

}

void ExercisePlan::editDate() {
	std::string date;
	std::cout << "current date: " << getDate() << std::endl;
	std::cout << "New date: ";
	std::cin >> date;
	std::cout << std::endl << "Date set to: " << date << std::endl;
	setDate(date);
}

// Overloaded stream insertion operator for displaying an ExercisePlan object
std::ostream& operator<<(std::ostream& os, const ExercisePlan& plan) {
	os << "Plan name: " << plan.getName() << std::endl;
	os << "Goal calories: " << plan.getGoalStep() << std::endl;
	os << "Date: " << plan.getDate() << std::endl;
	return os;
}

// Overloaded stream insertion operator for writing an ExercisePlan object to a file
std::ofstream& operator<<(std::ofstream& ofs, const ExercisePlan& plan) {
	ofs << plan.getName() << std::endl;
	ofs << plan.getGoalStep() << std::endl;
	ofs << plan.getDate();
	return ofs;
}

// Overloaded stream extraction operator for reading an ExercisePlan object from a file
std::ifstream& operator>>(std::ifstream& ifs, ExercisePlan& plan) {
	std::string name, date;
	int goalSteps;
	if (ifs >> name >> goalSteps >> date) {
		plan.setName(name);
		plan.setGoalStep(goalSteps);
		plan.setDate(date);
	}
	return ifs;
}