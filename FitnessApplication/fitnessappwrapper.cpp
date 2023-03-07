/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: fitnessappwrapper.cpp
* Date: 3/1/23
* Description: Source file for the FitnessAppWrapper class with all function and constructor definitions,
*			   which will use the rest of the classes in the project to create the main executable logic. 
*			   Contains a list for a weekly exercise plan and weekly diet plan. This class also holds file 
*			   streams to read and write to "dietPlans.txt" and "exercisePlans.txt"
*/

#include "fitnessappwrapper.hpp"

//default constructor
FitnessAppWrapper::FitnessAppWrapper() {

	//initialize lists to size 7 
	dietPlans = new DietList();
	exercisePlans = new ExerciseList();

	for (int i = 0; i < 7; i++) {
		dietPlans->insert(new DietPlan());
		exercisePlans->insert(new ExercisePlan());
	}

}

//main executable function
void FitnessAppWrapper::runApp(void) {
	int choice = 0;
	do {
		choice = displayMenu(); //get user menu input
		
		switch (choice) {

		case 1: //load diet plans
			mReadDietF.open("dietPlans.txt");
			loadWeeklyPlan(mReadDietF, *dietPlans);
			mReadDietF.close();
			break;

		case 2: //load exercise plans
			mReadExerciseF.open("exercisePlans.txt");
			loadWeeklyPlan(mReadExerciseF, *exercisePlans);
			mReadExerciseF.close();
			break;

		case 3: //store diet plans to file
			mWriteDietF.open("dietPlans.txt");
			storeWeeklyPlan(mWriteDietF, *dietPlans);
			mWriteDietF.close();
			break;

		case 4: //store exercise plans to file
			mWriteExerciseF.open("exercisePlans.txt");
			storeWeeklyPlan(mWriteExerciseF, *exercisePlans);
			mWriteExerciseF.close();
			break;

		case 5: //display diet plans to console
			displayWeeklyPlan(*dietPlans);
			break;

		case 6: //display exercise plans to console
			displayWeeklyPlan(*exercisePlans);
			break;

		case 7: //select and edit plans from diet plans
			editWeeklyPlan(*dietPlans);
			break;

		case 8: //select and edit plans from exercise plans
			editWeeklyPlan(*exercisePlans);
			break;

		};
			
	} while (choice != 9);

	//store weekly diet and exercise plans before exiting
	mWriteDietF.open("dietPlans.txt");
	storeWeeklyPlan(mWriteDietF, *dietPlans);
	mWriteDietF.close();
	mWriteExerciseF.open("exercisePlans.txt");
	storeWeeklyPlan(mWriteExerciseF, *exercisePlans);
	mWriteExerciseF.close();

	std::cout << "Goodbye!";

}

//display menu options to console and return user input
int FitnessAppWrapper::displayMenu() {
	int choice = -1;
	int attempt = 0;
	do {

		if (attempt > 0) { //invalid input catch
			std::cout << "Invalid input, please try again" << std::endl;
			attempt--;
		}
		attempt++;
		std::cout << "1. Load weekly diet plan from file" << std::endl;
		std::cout << "2. Load weekly exercise plan from file" << std::endl;
		std::cout << "3. Store weekly diet plan to file" << std::endl;
		std::cout << "4. Store weekly exercise plan to file" << std::endl;
		std::cout << "5. Display weekly diet plan to screen" << std::endl;
		std::cout << "6. Display weekly exercie plan to screen" << std::endl;
		std::cout << "7. Edit daily diet plan" << std::endl;
		std::cout << "8. Edit daily exercise plan" << std::endl;
		std::cout << "9. Save and Exit" << std::endl << std::endl;
		std::cout << "choice ";
		std::cin >> choice;
		system("cls");

	} while (choice <= 1 && choice >= 9);

	return choice;

}

//DIET PLAN: load one daily plan
void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, DietPlan& plan) {
	std::string line;
	if (fileStream.is_open() && getline(fileStream, line)) {
		//set name
		plan.setName(line);
		if (getline(fileStream, line)) {
			//set goal cal
			plan.setGoalCal(stoi(line));
		}
		if (getline(fileStream, line)) {
			//set date
			plan.setDate(line);
		}
		getline(fileStream, line);//skip empty line
	}
}

//EXERCISE PLAN: load one daily plan
void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, ExercisePlan& plan) {
	std::string line;
	if (fileStream.is_open() && getline(fileStream, line)) {
		//set name of plan
		plan.setName(line);
		if (getline(fileStream, line)) {
			//set goal steps of plan
			plan.setGoalStep(stoi(line));
		}
		if (getline(fileStream, line)) {
			//set date of plan
			plan.setDate(line);
		}
		getline(fileStream, line);//skip empty line
	}
}

//DIET PLAN: load weekly plan using loadDailyPlan
void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, DietList& dietList) {

	std::string line;

	if (fileStream.is_open()) {
		
		int i = 0;
		while (!fileStream.eof()) {
			//load a daily plan and add it to the diet list
				loadDailyPlan(fileStream, *dietList.get(i));
				i++;
		}
		
	}
}

//EXERCISE PLAN: load weekly plan using loadDailyPlan
void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, ExerciseList& exerciseList) {

	std::string line;

	if (fileStream.is_open()) {

		int i = 0;
		while (!fileStream.eof()) {
			//load a daily plan and add it to the exercise list
			loadDailyPlan(fileStream, *exerciseList.get(i));
			i++;
		}
	}
}

//DIET PLAN: display daily plan to console
void FitnessAppWrapper::displayDailyPlan(DietPlan& dietPlan) {
	std::cout << dietPlan;
}

//EXERCISE PLAN: display daily plan to console
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& exercisePlan) {
	std::cout << exercisePlan;
}

//DIET PLAN: display weekly plan using displayDailyPlan
void FitnessAppWrapper::displayWeeklyPlan(DietList& dietList) {
	std::cout << "Displaying weekly Diet Plan" << std::endl << std::endl;
	for (int i = 0; i < dietList.getSize(); i++) {
		std::cout << "Day " << i + 1 << std::endl;
		//display the daily plan for day i
		displayDailyPlan(*dietList.get(i));
		std::cout << std::endl;
	}
}

//EXERCISE PLAN: display weekly plan using displayDailyPlan
void FitnessAppWrapper::displayWeeklyPlan(ExerciseList& exerciseList) {
	std::cout << "Displaying weekly Exercise Plan" << std::endl << std::endl;
	for (int i = 0; i < exerciseList.getSize(); i++) {
		std::cout << "Day " << i + 1 << std::endl;
		//display the daily plan for day i
		displayDailyPlan(*exerciseList.get(i));
		std::cout << std::endl;
	}

}



//DIETPLAN: store a daily plan to a file
void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, DietPlan& dietPlan) {
	if (!fileStream.is_open()) { //file is not open catch
		std::cerr << "Error: File stream is not open." << std::endl;
	}

	else {
		//write daily plan to file using overloaded string operator
		fileStream << dietPlan;
	}
	
}

//EXERCISEPLAN: store a daily plan to a file
void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, ExercisePlan& exercisePlan) {
	if (!fileStream.is_open()) { //file is not open catch
		std::cerr << "Error: File stream is not open." << std::endl;
	}

	else {
		//write daily plan to file using overloaded string operator
		fileStream << exercisePlan;
	}

}

//DIET PLAN: store a weekly plan to a file for a linked list
void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, DietList& dietList) {
	if (!fileStream.is_open()) { //file is not open catch
		std::cerr << "Error: File stream is not open." << std::endl;
		return;
	}

	for (int i = 0; i < 7; i++) { // iterate over 7 days in a week

		DietPlan* plan = dietList.get(i); // get plan for day i
		fileStream << *plan;
		if (i != 6) { // not the last day
			fileStream << std::endl << std::endl; // add newline characters
		}
	}
}

//EXERCISE PLAN: store a weekly plan to a file for a linked list
void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, ExerciseList& exerciseList) {
	if (!fileStream.is_open()) { //file is not open catch
		std::cerr << "Error: File stream is not open." << std::endl;
		return;
	}

	for (int i = 0; i < 7; i++) { // iterate over 7 days in a week

		ExercisePlan* plan = exerciseList.get(i); // get plan for day i
		fileStream << *plan;

		if (i != 6) { //not the last day
			fileStream << std::endl << std::endl; // add newline characters
		}

	}
}

//DIET PLAN: edit attributes of daily plan
void FitnessAppWrapper::editDailyPlan(DietPlan& dietPlan) {
	//initialize temporary variables
	int choice = 0;
	std::string name = "";
	std::string date = "";
	int goal = 0;
	do { //loop until user wants to leave
		system("cls");
		displayDailyPlan(dietPlan); //display current daily plan

		//prompt edits
		std::cout << std::endl << "What would you like to edit?" << std::endl;
		std::cout << "(1) Name" << std::endl;
		std::cout << "(2) Goal" << std::endl;
		std::cout << "(3) Date" << std::endl;
		std::cout << "(4) Exit" << std::endl;
		std::cin >> choice; //user chooses which field to edit
		switch (choice) {
		case 1: //edit name
			system("cls");
			dietPlan.editName();
			break;
		case 2: //edit goal
			system("cls");
			dietPlan.editGoal();
			break;
		case 3: //edit date
			system("cls");
			dietPlan.editDate();
			break;
		}
	} while (choice != 4);
	system("cls");
}

//EXERCISE PLAN: edit attributes of daily plan
void FitnessAppWrapper::editDailyPlan(ExercisePlan& exercisePlan) {
	//initialize temporary variables
	int choice = 0;
	std::string name = "";
	std::string date = "";
	int goal = 0;
	do { //loop until user wants to leave
		system("cls");
		displayDailyPlan(exercisePlan); //display current daily plan
		//prompt edits
		std::cout << std::endl << "What would you like to edit?" << std::endl;
		std::cout << "(1) Name" << std::endl;
		std::cout << "(2) Goal" << std::endl;
		std::cout << "(3) Date" << std::endl;
		std::cout << "(4) Exit" << std::endl;
		std::cin >> choice; //user chooses which field to edit
		switch (choice) {
		case 1: //edit name
			system("cls");
			exercisePlan.editName();
			break;
		case 2: //edit goal
			system("cls");
			exercisePlan.editGoal();
			break;
		case 3: //edit date
			system("cls");
			exercisePlan.editDate();
			break;
		}
	} while (choice != 4);
	system("cls");
}

//DIET PLAN: select and edit daily plans from weekly plan
void FitnessAppWrapper::editWeeklyPlan(DietList& dietList) {
	int choice = 0;
	system("cls");
	do { //loop until user wants to quit
		displayWeeklyPlan(dietList); //display current weekly plan
		std::cout << std::endl << "Enter '0' if you want to exit" << std::endl;
		std::cout << "What day would you like to edit: ";
		std::cin >> choice;
		system("cls");
		if (choice != 0)
			editDailyPlan(*(dietList.get(choice - 1))); //edit plan based on user choice
	} while (choice != 0);
}

//EXERCISE PLAN: select and edit daily plans from weekly plan
void FitnessAppWrapper::editWeeklyPlan(ExerciseList& exerciseList) {
	int choice = 0;
	system("cls");
	do { //loop until user wants to quit
		displayWeeklyPlan(exerciseList); //display current weekly plan
		std::cout << std::endl << "Enter '0' if you want to exit" << std::endl;
		std::cout << "What day would you like to edit: ";
		std::cin >> choice;
		system("cls");
		if (choice != 0)
			editDailyPlan(*(exerciseList.get(choice - 1))); //edit plan based on user choice
	} while (choice != 0);
}





