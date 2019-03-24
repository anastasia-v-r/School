// Includes
#include <iostream>
#include "Funcs.h"

// Variables
int* arrPtr = nullptr;
int temp;
int userInput;

// Entry Point
int main() {
	std::cout << "How many students were surveyed?\n"; // Get array size
	std::cin >> userInput;
	while (userInput < 0) { // Validate input
		std::cout << "Invalid input, please try again.\n";
		std::cin >> userInput;
	}
	arrPtr = new int[userInput]; // Create array using a pointer
	for (int i = 0; i < userInput; ++i) { // Fill array
		std::cout << "How many movies did student " << i + 1 << " watch?\n";
		std::cin >> temp;
		while (temp < 0) { // Validate input
			std::cout << "Invalid input, please try again.\n";
			std::cin >> temp;
		}
		arrPtr[i] = temp;
	}
	
	sort(arrPtr, userInput); // Sort the array
	//printArr(arrPtr, userInput); // Print the array  //Debug
	median(arrPtr, userInput); // Find middle of array
	mean(arrPtr, userInput); // Find average of array
	mode(arrPtr, userInput); // Find mode of array

	delete [] arrPtr; // Free up memory
	arrPtr = nullptr; // null the ptr for the array

	std::cin.ignore(10);
}
