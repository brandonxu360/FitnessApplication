/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: fitnessappwrapper.hpp
* Date: 3/1/23
* Description: Header file for the FitnessAppWrapper class, which will use the rest of the classes in the
*			   project to create the main executable logic. Contains a list for a weekly exercise plan and weekly
*			   diet plan. This class also holds file streams to read and write to "dietPlans.txt" and "exercisePlans.txt"
*/

#include "header.hpp"
#include "dietlist.hpp"
#include "exerciselist.hpp"
#include "exerciseplan.hpp"
#include "dietplan.hpp"

class FitnessAppWrapper {
//public member functions

public:

	FitnessAppWrapper(); //default constructor

	void runApp(void); //main executable function

	int displayMenu(); //display menu and return user choice

	//ALL FUNCTIONS BELOW ARE OVERLOADED TO TAKE BOTH DIETPLAN AND EXERCISEPLAN OBJECTS
	//load daily plan functions
	void loadDailyPlan(std::fstream& filestream, DietPlan& plan);
	void loadDailyPlan(std::fstream& filestream, ExercisePlan& plan);

	//load weekly plan (using loadDailyPlan functions)
	void loadWeeklyPlan(std::fstream& fileStream, DietList& dietList);
	void loadWeeklyPlan(std::fstream& fileStream, ExerciseList& exerciselist);

	//display daily plan to console
	void displayDailyPlan(DietPlan& dietPlan);
	void displayDailyPlan(ExercisePlan& exercisePlan);

	//display weekly plan to console (using displayDailyPlan functions)
	void displayWeeklyPlan(DietList& dietList);
	void displayWeeklyPlan(ExerciseList& exerciseList);

	//store a daily plan to a file
	void storeDailyPlan(std::ofstream& fileStream, DietPlan& dietPlan);
	void storeDailyPlan(std::ofstream& fileStream, ExercisePlan& exercisePlan);

	//store weekly plan to file (using storeDailyPlan function)
	void storeWeeklyPlan(std::ofstream& fileStream, DietList& dietList);
	void storeWeeklyPlan(std::ofstream& fileStream, ExerciseList& exerciseList);

	//edit attributes of a daily plan
	void editDailyPlan(DietPlan& dietPlan);
	void editDailyPlan(ExercisePlan& exercisePlan);

	//select and edit daily plans from weekly plan
	void editWeeklyPlan(DietList& dietList);
	void editWeeklyPlan(ExerciseList& exerciseList);



//private attributes
private:

	//weekly diet and exercise plan lists
	DietList* dietPlans;
	ExerciseList* exercisePlans;

	//files for diet and exercise plans
	std::fstream mReadDietF;
	std::ofstream mWriteDietF;
	std::fstream mReadExerciseF;
	std::ofstream mWriteExerciseF;
};