#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>
#include "Funcs.h"
#include "Structs.h"

int main() {
	// Usings
	using std::cout;
	using std::cin;
	// Global Vars
	int userchoice;
	// Drink Machine Struct
	machine vendingMachine = {
		{std::vector<drink> {
				{"Cola", .75, 20},
				{"Root Beer", .75, 20 },
				{"Lemon-Lime", .75, 20 },
				{"Grape Soda", .80, 20 },
				{"Cream Soda", .80, 20 }
			}
		},
		{0} 
	};
	// Program Core Loop
	while (true) {
		displayContents(vendingMachine);
		cout << "Enter a number to purchase a drink or 0 to exit.\n";
		cin >> userchoice;
		if (userchoice == 0) {
			std::cout << "\nThe total revenue during this session for the machine was : $" << std::fixed << std::showpoint << std::setprecision(2) << vendingMachine.revenue;
			std::cout << "\n\n";
			for (int count = 5; count > 0; --count) {
				std::cout << "Exiting in " << count;
				Sleep(500);
				std::cout << ".";
				Sleep(500);
				std::cout << ".\n";

			}
			break;
		}
		else if (userchoice > (vendingMachine.inventory.size()))
		{
			std::cout << "\nThis option does not exist, please try again.\n";
		}
		else {
			buyDrink(vendingMachine, userchoice);
		}
		//display total money
	}
}