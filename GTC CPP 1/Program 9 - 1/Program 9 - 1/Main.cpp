#include <iostream>
#include "Binary.h"

int main()
{
	bool found = false;
	int input,position;
	int list[18] = {  5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
					8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
					1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
	
	std::cout << "Which charge account number are you verifying?\n";
	std::cin >> input;

	found = BinarySearch(list, input, 18);
	
	if (found == true)
	{
		cout << "Your number " << input << " is valid an exists at "
	}
	else
	{

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