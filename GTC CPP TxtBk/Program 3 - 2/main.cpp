#include <iostream>
#include <iomanip>

int main() {
	float classA = 15, classB = 12, classC = 9;
	std::cout << "Please enter how many tickets were sold." << std::endl;
	std::cout << "Class-A Seats : ";
	std::cin >> classA;
	classA *= 15;
	std::cout << "Class-B Seats : ";
	std::cin >> classB;
	classB *= 12;
	std::cout << "Class-C Seats : ";
	std::cin >> classC;
	classC *= 9;
	float profit = classA + classB + classC;
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	std::cout << "Your total profit is, $" << profit << "." << std::endl;
	std::cout << "Press any key to exit." << std::endl;
	std::cin.ignore(2);
}