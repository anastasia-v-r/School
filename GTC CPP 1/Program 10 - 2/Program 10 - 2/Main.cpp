// Includes
#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>
#include "Funcs.h"
#include "Structs.h"

// Usings
using std::cout;
using std::cin;

//Entry Point
int main() {

	// Variables
	std::vector<speaker> spkrBureau(10, defSpkr);
	char progress = '0';
	bool end = false;
	char choice;

	do {
		cout << "Please enter which option you'd like to choose,\n";
		cout << "(A) - Fill entire list\n";
		cout << "(B) - Edit single element\n";
		cout << "(C) - Display the entire array\n";
		cout << "(F) - Exit the program\n";
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case('A'):
			fillVec(spkrBureau);
			std::cout << "Would you like to continue? [y/n]\n";
			std::cin >> progress;
			progress = tolower(progress);
			break;
		case('B'):
			std::cout << "Which position would you like to edit in specific?\n";
			int vec;
			std::cin >> vec;
			while (vec < 0 || vec > (spkrBureau.size() - 1)) {
				std::cout << "That was an invalid element, please try again. This list only contains elements 0 - " << spkrBureau.size() - 1 << "\n";
				std::cin >> vec;
			}
			editVec(spkrBureau, vec);
			std::cout << "Would you like to continue? [y/n]\n";
			std::cin >> progress;
			progress = tolower(progress);
			break;
		case('C'):
			readVec(spkrBureau);
			std::cout << "Would you like to continue? [y/n]\n";
			std::cin >> progress;
			progress = tolower(progress);
			break;
		case('F'):
			end = true;
			break;
		default:
			std::cout << "The value entered was invalid, please try again.\n\n";
			break;
		}
		
	} while (progress == 'y' || end == true);

	exit();

}

/*Program 2:

Write a program that keeps track of a speakers’ bureau. The program should use a structure to store the following data about a speaker:

Name
Telephone Number
Speaking Topic
Fee Required

The program should use an array of at least 10 structures. It should let the user enter data into the array, change the contents of any 
element, and display all the data stored in the array. The program should have a menu-driven user interface.

Input Validation: When the data for a new speaker is entered, be sure the user enters data for all the fields. No negative amounts should be entered for a speaker’s fee.*/