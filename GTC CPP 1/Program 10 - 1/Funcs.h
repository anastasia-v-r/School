#pragma once
#include <iostream>
#include <iomanip>
#include "Structs.h"

void displayContents(machine vec) {
	int vecSize = vec.inventory.size();
	std::cout << "+-----+-----------+------+-----+\n";
	std::cout << "|Slot |Beverage   |Price |Stock|\n";
	std::cout << "+-----+-----------+------+-----+\n";

	for (int count = 0; count < vecSize; ++count) {
		std::cout << "|[" << count + 1 << "]  |" << std::setw(10) << std::left << vec.inventory[count].name << " |" << std::setw(4) << std::showpoint << std::setprecision(2) << vec.inventory[count].cost << "  |" << std::setw(4) << vec.inventory[count].quantity << " |\n";
		std::cout << "|     |           |      |     |\n";
	}
	std::cout << "+-----+-----------+------+-----+\n\n";
}

void buyDrink(machine& vec, int choice) {
	float money;
	
	if (vec.inventory[choice - 1].quantity > 0) {
		std::cout << "\nPlease indicate the amount of money inserted. (Maximum $1.00)\n";
		std::cin >> money;

		while (money > 1 || money <= 0) {
			if (money > 1) {
				std::cout << "\nThe amount inserted is too high, please try again with a lower amount.\n";
				std::cin >> money;
			}
			else if (money <= 0) {
				std::cout << "\nThe amount inserted is too low, please try again with a higher amount.\n";
				std::cin >> money;
			}
			else {
				std::cout << "\nCritical Error, exiting.\n";
				break;
			}
		}

		std::cout << "\nDispensing 1 " << vec.inventory[choice - 1].name << "\n";
		vec.revenue += vec.inventory[choice - 1].cost;
		--vec.inventory[choice - 1].quantity;
		std::cout << "\nYour change is $" << std::showpoint << std::setprecision(2) << (money - vec.inventory[choice - 1].cost) << "\n\n";
	}
	else {
		std::cout << "\nSorry, but that drink is out of stock. Your change has been returned.\n\n";
	}
}