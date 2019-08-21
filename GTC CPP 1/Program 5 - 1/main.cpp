#include <iostream>
#include <string>
#include "funcs.h"

const int arrSize = 5;
std::string areas[arrSize] = { "north", "east", "south", "west", "central" };
int accs[arrSize];

int main()
{
	for (int count = 0; count < arrSize; ++count)
	{
		accs[count] = getNumAccidents(areas[count]);
	}

	findLowest(areas, accs, arrSize);

	std::cin.ignore(2);
}
