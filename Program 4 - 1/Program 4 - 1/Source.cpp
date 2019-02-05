#include <iostream>
#include <iomanip>

int main()
{
	int books = 0, points = 0, totalPoints = 0, count = 0;
	std::cout << "To exit this menu, please input a negative whole number.\n\nOtherwise, please input the amount of books you purchased this month.\n";
	
	do
	{
		std::cin >> books;
		switch (books)
		{
		case (0):
			points = 0;
			break;
		case (1):
			points = 5;
			break;
		case (2):
			points = 15;
			break;
		case (3):
			points = 30;
			break;
		default:
			points = 60;
			break;
		}
		std::cout << "You have earned " << points << " for this month.\n";
		totalPoints += points;
		++count;
	} while (books >= 0);

	std::cout << "Over the course of " << count << " months, You've earned a total of " << totalPoints << ".\n";
	system("Pause");
}