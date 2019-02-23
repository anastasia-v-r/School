#include <iostream>

int main()
{
	
	int second = 0;
	float seconds = 0, min = 0, hour = 0, day = 0;

	do
	{

		std::cout << "Please enter an amount of seconds in whole numbers.\n\n";

		std::cin >> second;
		std::cout << "\n";

		seconds = second;

		if (seconds > 86400)
		{
			day = seconds / 86400;
			std::cout << seconds << " seconds is, " << day << " days.\n\n";
		}
		else if (seconds > 3600)
		{
			hour = seconds / 3600;
			std::cout << seconds << " seconds is, " << hour << " hours.\n\n";
		}
		else if (seconds > 60)
		{
			min = seconds / 60;
			std::cout << seconds << " seconds is, " << min << " minutes.\n\n";
		}
		
		
	} while (seconds >= 0);

}
