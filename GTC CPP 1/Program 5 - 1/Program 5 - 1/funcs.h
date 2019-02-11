#pragma once
#include <iostream>
#include <string>

int getNumAccidents(std::string area)
{
	unsigned int userInput;
	std::cout << "How many accidents occurced in the " << area << " area?\n";
	while (true)
	{
		std::cout << "Please enter a positive integer.\n";
		std::cin >> userInput;
		if (std::cin.bad())
		{
			break;
		}
		else
		{
			return userInput;
		}
	}
}

void findLowest(std::string area[], int accs[], int arrSize)
{	
	int count = 0, min = 0, minSpot = 0;

	min = accs[count++];
	do
	{
		if (accs[count] < min)
		{
			min = accs[count];
			++minSpot;
		}
	} while (++count < arrSize);

	std::cout << "The lowest accident rate region is " << area[minSpot] << " with only " << min << " accidents.";

}
