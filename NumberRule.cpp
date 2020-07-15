//	File Name: NumberRule.cpp
//	Name: Ervin Centeno
//	Project Name: Data Structure: Project 1
//	Date: January 25, 2019

/*	Description: This program is meant to find out if the users 
	input is valid and follows the rule of positive integers in
	sequential order. */

#include "pch.h"		// Default source file.
#include <cassert>		// Used for assert.
#include <cstdlib>	
#include <limits>
#include <iostream>		// For input/ouput commands
#define NDEBUG

using namespace std;

void order_check(int& n1, int& n2, int& n3, bool& check);
// Precondition: The user must input three integers to proceed.

/*	Postcondition: The function will assign true or false to the bool 
	variable that will be passed back into the main function.
	This function is meant to check if the three inputs are in sequential order
	 and returns false if they are not and vice versa if they are. */

int main()
{
	int num1, num2, num3;	// Intiate the three numbers to be checked from cin.
	
	bool check = 0;
	char replay = 'Y';			
	
	while(replay == 'Y' || replay == 'y'){
		
		cout << "Can you guess the rule for this game?\n"
			<< "Type in three integers and find out: ";

		do {

			while (1) {
				cin >> num1 >> num2 >> num3;
				//assert(num1, num2, num3);		// assert stops program if an error occurs
				if (cin.fail()) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (!cin.fail())
					break;
			}

			order_check(num1, num2, num3, check);

		} while (check == false);

		cout << "That is correct! Want to try another set of integers? Type in Y for yes or N for no: ";
		cin >> replay;
	} 
	cout << "Thanks for playing!";

	return 0;
}

void order_check(int& n1, int& n2, int& n3, bool& check) {

	if ((n1 > n2) || (n2 > n3) || (n1 > n3)) {					/*	if statement to check for order
																	least to greatest. */
		check = false;
		cout << "Not quite try another set of numbers: ";
	}
	else if ((n1 < 0) || (n2 < 0) || (n3 < 0)) {	/*	if statement to check if inputs
																	are negative. */
		check = false;
		cout << "Not quite try another set of numbers: ";
	}
	else
		check = true;
}
