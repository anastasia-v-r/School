#include <iostream>
#include "Binary.h"

int main()
{
	bool found = false;
	const int arrSize = 18;
	int input,position;
	int list[arrSize] = {1005231,  1250255, 1302850, 3852085, 4520125, 4562555, 
						4581002, 5050552, 5552012, 5658845, 6545231, 7576651,
						7825877, 7881200, 7895122, 8080152, 8451277, 8777541 };
	
	std::cout << "Which charge account number are you verifying?\n";
	std::cin >> input;

	found = BinarySearch(list, input, arrSize, position);
	
	if (found == true)
	{
		std::cout << "Your number " << input << " is valid and exists at List[" << position << "]\n";
		system("Pause");
	}
	else if (found == false)
	{
		std::cout << "Your number " << input << " is not valid and exists at no location in 'List'\n";
		system("Pause");
	}
	else
	{
		std::cout << "The program has encountered a fatal error, shutting down now.\n";
		system("Pause");
	}

}

/*Program 1:

Write a program that lets the user enter a charge account number. The program should 
determine if the number is valid by checking for it in the following list:

5658845 4520125 7895122 8777541 8451277 1302850
8080152 4562555 5552012 5050552 7825877 1250255
1005231 6545231 3852085 7576651 7881200 4581002

The list of numbers above should be initialized in a single-dimensional array. A 
simple binary search should be used to locate the number entered by the user. If 
the user enters a number that is in the array, the program should display a message 
saying that the number is valid. If the user enters a number that is not in the array,
the program should display a message indicating that the number is invalid.*/