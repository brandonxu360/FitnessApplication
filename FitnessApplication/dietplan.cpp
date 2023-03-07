/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: dietplan.cpp
* Date: 3/1/23
* Description: Source file for the DietPlan object, which represents an diet plan for a single
*			   day with name, goal calories, and date attributes. Also includes overloaded stream operators
*			   for easier use of DietPlan objects.
*/

#include "dietplan.hpp"

//default constructor
DietPlan::DietPlan() {

	//set attributes to default values
	mGoalCal = 0;
	mName = "";
	mDate = "";

}

//copy constructor
DietPlan::DietPlan(DietPlan& origPlan) { 

	//copy values over
	mGoalCal = origPlan.mGoalCal;
	mName = origPlan.mName;
	mDate = origPlan.mDate;

}

//deconstructor
DietPlan::~DietPlan() {

};

//setter functions
void DietPlan::setGoalCal(int newGoalCal) {
	mGoalCal = newGoalCal;
}

void DietPlan::setName(std::string newName) {
	mName = newName;
}

void DietPlan::setDate(std::string newDate) {
	mDate = newDate;
}

//getters
std::string DietPlan::getName() const {
	return mName;
}

int DietPlan::getGoalCalories() const {
	return mGoalCal;
}

std::string DietPlan::getDate() const {
	return mDate;
}

//edit functions - get user input and set field accordingly
void DietPlan::editName() {
	std::string name;
	std::cout << "current name: " << getName() << std::endl;
	std::cout << "New name: ";
	std::cin >> name;
	std::cout << std::endl << "Name set to: " << name << std::endl;
	setName(name);
}

void DietPlan::editGoal() {
	int goal;
	//display current goal and prompt new goal
	std::cout << "current goal: " << getGoalCalories() << "calories" << std::endl;
	std::cout << "New goal: ";
	std::cin >> goal; //get user input for new goal
	std::cout << std::endl << "Goal set to " << goal << " calories" << std::endl;
	setGoalCal(goal); //set new goal to user input

}

void DietPlan::editDate()
{
	std::string date;
	std::cout << "current date: " << getDate() << std::endl;
	std::cout << "New date: ";
	std::cin >> date;
	std::cout << std::endl << "Date set to: " << date << std::endl;
	setDate(date);
}

// Overloaded stream insertion operator for displaying a DietPlan object
std::ostream& operator<<(std::ostream& os, const DietPlan& plan) {
	os << "Plan name: " << plan.getName() << std::endl;
	os << "Goal calories: " << plan.getGoalCalories() << std::endl;
	os << "Date: " << plan.getDate() << std::endl;
	return os;
}

// Overloaded stream insertion operator for writing a DietPlan object to a file
std::ofstream& operator<<(std::ofstream& ofs, const DietPlan& plan) {
	ofs << plan.getName() << std::endl;
	ofs << plan.getGoalCalories() << std::endl;
	ofs << plan.getDate();
	return ofs;
}

// Overloaded stream extraction operator for reading a DietPlan object from a file
std::fstream& operator>>(std::fstream& ifs, DietPlan& plan) {
	std::string name, date;
	int goalCalories;
	if (ifs >> name >> goalCalories >> date) {
		plan.setName(name);
		plan.setGoalCal(goalCalories);
		plan.setDate(date);
	}
	return ifs;
}