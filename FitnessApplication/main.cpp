/*
* Name: Brandon Xu
* Project: FitnessApplication
* File: main.cpp
* Date: 3/1/23
* Description: Main file where the FitnessAppWrapper object is created and the main executable function, runApp(), is called.
*/

#include "dietplan.hpp"
#include "exerciseplan.hpp"
#include "fitnessappwrapper.hpp"

int main(void) {

	//new fitnessappwrapper object
	FitnessAppWrapper application;

	//run the main executable function
	application.runApp();

	return 0;
}

/*
Monday
5000
2/28/23

Tuesday
5500
3/01/23

Wednesday
4500
3/02/23

Thursday
6000
3/03/23

Friday
10000
3/04/23

Saturday
3400
3/05/23

Sunday
5000
3/06/23

*/