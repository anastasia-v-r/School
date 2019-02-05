#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>


int main()
{
	const float pi = 3.14159;
	int userInput = 0, count = 0;
	float area = 0;
	float radius = 0, length = 0, width = 0, base = 0, height = 0;
	std::string zeroNegError = "The number you input was not above 0, please try again.\n";


	do
	{
		std::cout << "[Geometry Calculator]\n1. Calculate the Area of a Circle\n2. Calculate the Area of a Rectangle\n3. Calculate the Area of a Triangle\n4. Quit\n\nEnter your choice(1 - 4)\n";
		
		do
		{
			std::cin >> userInput;
			if (userInput > 4 || userInput < 1)
			{
				std::cout << "\nThat number was invalid, please try again.\n\n";
			}
		} while (userInput > 4 || userInput < 0);
		
		switch (userInput)
		{
		case (1):
			std::cout << "\nPlease enter the radius of the circle.\n";
			do
			{
				std::cin >> radius;
				if (radius <= 0)
				{
					std::cout << zeroNegError;
				}
			} while (radius <= 0);
			area = (pi * (pow(radius, 2)));
			std::cout << "\nThe area of a circle with the radius of " << radius << " is " << area << "\n\n\n";
			break;
		case (2):
			std::cout << "\nPlease enter the length and width.\n";
			do
			{
				std::cin >> length >> width;
				if (length <= 0 || width <= 0)
				{
					std::cout << zeroNegError;
				}
			} while (length <= 0 || width <= 0);
			area = length * width;
			std::cout << "\nThe area of a rectangle with the length of " << length << " and the width of " << width << " is " << area << ".\n\n\n";
			break;
		case (3):
			std::cout << "\nPlease enter the base and height.\n";
			do
			{
				std::cin >> base >> height;
				if (base <= 0 || height <= 0)
				{
					std::cout << zeroNegError;
				}
			} while (base <= 0 || height <= 0);
			area = base * height * .5;
			std::cout << "\nThe area of a triangle with the base of " << base << " and the height of " << height << " is " << area << ".\n\n\n";
			break;
		}
	} while (userInput < 4 && userInput >= 0);
	if (userInput == 4)
	{
		std::cout << "Exiting in \n";
		for (count = 3; count > 0; --count)
		{
			std::cout << count;
			Sleep(200);
			std::cout << ".";
			Sleep(200);
			std::cout << ".\n";
			Sleep(1000);
		}
	}
}