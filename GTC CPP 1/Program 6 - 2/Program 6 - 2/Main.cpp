#include <iostream>
#include <fstream>
#include <string>
#include "check.h"
#include "converter.h"

int main() 
{
	int bumpPop, steps;
	float currentHeight, currentDoor;
	char heightType;
	std::string name, result;
	std::ifstream bumpIn;
	std::ofstream bumpOut;

	bumpIn.open("bumpkins-in.txt");
	bumpOut.open("bumpkins-out.txt");

	if (bumpIn.is_open())
	{
		bumpIn >> bumpPop;
		for (int count = 0; count < bumpPop; ++count)
		{
			bumpIn >> name;
			bumpOut << name << "\n";
			bumpIn >> steps;
			bumpIn >> currentHeight;
			bumpIn >> heightType;
			convert(currentHeight, heightType);
			for (int count = 0; count < steps; ++count)
			{
				bumpIn >> currentDoor;
				bumpIn >> heightType;
				convert(currentDoor, heightType);
				result = check(currentHeight, currentDoor);
				bumpOut << "Doorway " << count << ": " << result << "\n";
			}
			bumpOut << "\n";
		}
	}
	else
	{
		std::cout << "Error opening file!";
	}

	bumpIn.close();
	bumpOut.close();

	std::cin.ignore(2);

}


