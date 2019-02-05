#include <iostream>

int main() {
	float capacity, maxDist;
	std::cout << "Enter your tanks max capacity, followed by your cars max miles on a single tank." << std::endl;
	std::cin >> capacity >> maxDist;
	float mileage = maxDist / capacity;
	std::cout << "Your cars MPG is, " << mileage << " ." << std::endl;
	std::cout << "Enter press any key to exit." << std::endl;
	std::cin.ignore(2);
}