#include <iostream>
#include <fstream>
#include "funcs.h"
#include <iomanip>

int main()
{
	using namespace std;
	float total;
	string name;
	char proceed;
	char choice;
	int count = 0;
	std::ofstream output;
	output.open("Patients.dat");

	output << "  ___________________________________________________________\n";
	
	do
	{
		++count;
		cout << "Is this patient an in-patient(i) or an out-patient(o)?\n";
		cin >> choice;

		switch (choice)
		{
		case('i'):
			inPatient(total, name);
			break;
		case('o'):
			outPatient(total, name);
			break;
		}
		
		cout << " |Patient[" << count << "][" << choice << "] | Name: " << setfill(' ') << setw(8) << name << " | Total Charges: $" << setw(10) << showpoint << fixed << setprecision(2) << total << "|\n";
		output << " |Patient[" << count << "][" << choice << "] | Name: " << setfill(' ') << setw(8) << name << " | Total Charges: $" << setw(10) << showpoint << fixed << setprecision(2) << total << "|\n";
		output << " |______________|________________|___________________________|\n";

		cout << "Would you like to proceed? [y/n]\n";
		cin >> proceed;
	} while (proceed == 'y');
	
	output.close();
}


/*

Write a program that computes and displays the charges for a patient’s hospital stay. First, the program should ask 
if the patient was admitted as an in-patient or an outpatient.

If the patient was an in-patient, the following data should be entered:

    The name of the patient
    The number of days spent in the hospital
    The daily rate
    Hospital medication charges
    Charges for hospital services (lab tests, etc.)

The program should ask for the following data if the patient was an out-patient:

    The name of the patient
    Charges for hospital services (lab tests, etc.)
    Hospital medication charges

Your program should output the results to the screen but also to a txt file that could be emailed to management.
Your outputted results should include the following:

    The patients name
    The total charges

Your program should also allow the user to process as many patients as they would like without having to restart the program. 
This means that the outputted file should have all of the patients that were processed during the exectuion of the program.

C++ Dos and Donts for this Assignment

You are expected to use the content from chapters 1 - 6 (expressions, I/O, loops, conditionals, and functions).
You are not to use arrays (chapter 7) or other advanced features to solve this problem.

You must have a good modularity i.e. use of functions.

Do not accept negative numbers for any data.

Submission

Use the drop box for your submission. Please submit your .cpp file and your output file.
*/