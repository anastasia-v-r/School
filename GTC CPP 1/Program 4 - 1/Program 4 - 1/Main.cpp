#include <iostream>

float floors = 0, cfloor = 0, frooms = 0, trooms = 0, croom = 0, occ = 0, tocc = 0;
char check;

int main()
{
	do
	{
		std::cout << "Please enter the amount of hotel floors. [Min:1]\n";
		std::cin >> floors;
		if (floors == 13)
		{
			++floors;
		}
	} while (floors < 1);
	
	for (cfloor = 1; cfloor <= floors; ++cfloor)
	{
		if (cfloor == 13)
		{
		
		}
		else
		{
			do
			{
				std::cout << "Please enter the amount of rooms on (Floor - " << cfloor << "). [Min:10]\n";
				std::cin >> frooms;
			} while (frooms < 10);

			trooms += frooms;
			
			do
			{
				std::cout << "Are there rooms occupied on this floor? [y/n]\n";
				std::cin >> check;
			} while (check != 'y' && check != 'n');
			
			if (check == 'y')
			{
				std::cout << "How many are occupied?\n";
				std::cin >> occ;
				tocc += occ;
			}
		}
	}
	float rate = tocc / trooms;
	rate *= 100;
	std::cout << "The hotel standing at " << floors << " floors tall with a total of " << trooms << " rooms. Is occupied at a " << rate << "% rate.\n";
	std::cin.ignore(2);
}
