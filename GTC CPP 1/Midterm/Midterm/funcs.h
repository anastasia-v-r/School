#pragma once
#include <iostream>
#include <string>
using namespace std;

void noNeg(float& input)
{
	cin >> input;

	if (input < 0)
	{
		do
		{
			cout << "Please input a positive value.\n";
			cin >> input;
		} while (input < 0);
	}
}

void inPatient(float& total, std::string& name)
{
	float days;
	float rate;
	float meds;
	float services;

	cout << "\nWhat is the name of the patient?\n";
	cin >> name;
	cout << "\nAnd how many days did they spend in the hospital?\n";
	noNeg(days);
	cout << "And what was the rate per day?\n";
	noNeg(rate);
	cout << "And how much was the total of Hospital Medication Charges?\n";
	noNeg(meds);
	cout << "And lastly, how much were the charges for hospital services such as lab tests?\n";
	noNeg(services);

	total = (days * rate) + meds + services;
}

void outPatient(float& total, std::string& name)
{
	float meds;
	float services;

	cout << "What is the name of the patient?\n";
	cin >> name;
	cout << "And how much was the total of Hospital Medication Charges?\n";
	noNeg(meds);
	cout << "And lastly, how much were the charges for hospital services such as lab tests?\n";
	noNeg(services);

	total = meds + services;
}


/*
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

Your program should output the results to the screen but also to a txt file that could be emailed to management. Your outputted results should include the following:

	The patients name
	The total charges
*/