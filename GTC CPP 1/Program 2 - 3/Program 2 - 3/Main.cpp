#include <iostream>
#include <iomanip>

int year = 0;
float level = 0;

int main()
{

	std::cout << std::setw(21) << "Water Levels\n";
	std::cout << "---------------------------\n";

	for (year = 0; year <= 25; ++year)
	{
		level += 1.5;
		std::cout << "[Year: " << std::setw(3) << year << "]" << std::setw(15) << "[Water Level: " << std::setw(5) << level << "]\n\n";

	}
	std::cin.ignore(2);
}
