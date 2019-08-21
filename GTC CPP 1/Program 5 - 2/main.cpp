#include <iostream>

float fallingDistansce(float g, int t)
{
	return .5 * g * pow(t, 2);
}

int main()
{
	const float g = 9.8;
	unsigned int time, timeLeft;
	bool good;

	do
	{
		std::cout << "Please enter the total time the object will fall.\n";
		std::cin >> time;
		if (std::cin.bad())
		{
			good = false;
			std::cout << "Invalid input, please try again.\n";
		}
		else
		{
			good = true;
			timeLeft = time;
		}
	} while (good != true);

	for (int count = 1; count <= time; ++count)
	{
		float dist = fallingDistansce(g, count);
		std::cout << "After " << count << " total seconds the object has fallen " << dist << "m .\n";
	}

	std::cin.ignore(2);
}
