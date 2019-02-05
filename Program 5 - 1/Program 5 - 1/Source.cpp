#include <iostream>
#include <iomanip>

int main()
{
	unsigned int userInput = 0;
	long double count = 0, sum = 0;

	std::cout << "Please input an integer between 0 and 4294967295\n";
	//Input and Input Validation all in 1 neat recursive block
	while (true)
	{
		std::cin >> userInput;
		if (std::cin.bad())
			continue;
		break;
	}

	std::cout << "Your value, " << userInput << " was valid!\n";

	for (count = 0; count <= userInput; count++)
	{
		sum = sum + count;
		//std::cout << "sum" << sum << " Count" << count << " Userinput" << userInput << "\n"; //Used for error checking
	}

	std::cout << "The sumber of all numbers between and including 0, and your choice " << userInput << " is, " << sum << "." << "\n";
	std::cout << "Hit any key to exit." << "\n";
	std::cin.ignore(2);
}