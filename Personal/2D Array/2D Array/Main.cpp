// Includes n Usings
#include <iostream>
using std::cout; using std::cin;
#include <vector>
using std::vector;
#include <chrono>
#include <thread>
// Variables
vector<vector<int>> grid2d;
int base, length;
// Entry Point
int main() {
	// Get base from user
	cout << "+---------------------------------------------+\n"
		<< "| What number would you like your base to be? |\n"
		<< "+---------------------------------------------+\n";
	cin >> base;
	// Validate input
	while (!(base > -10 && base < 10) && !(base == 0)) {
		cin >> base;
		cout << "+----------------------------------------+\n"
			<< "| Invalid input, please enter an integer |\n"
			<< "+----------------------------------------+\n";
	}
	// Get length from user
	cout << "+----------------------------------------+\n"
		<< "| How long do you want each array to be? |\n"
		<< "+----------------------------------------+\n";
	cin >> length;
	// Validate input
	while (!(length > 0 && length < INT_MAX)) {
		cin >> length;
		cout << "+-----------------------------------------------+\n"
			<< "| Invalid input, please enter a positive integer |\n"
			<< "+------------------------------------------------+\n";
	}
	// Generate cube
	grid2d.resize(length, vector<int>(length));
	// Fill cube
	for (int i = 1; i < length; ++i) {
		for (int j = 1; j < length; ++j) {
			grid2d[i][j] = ((i * base)*(j * base));
		}
	}
	// Print cube
	for (int i = 1; i < length; ++i) {
		for (int j = 1; j < length; ++j) {
			if (grid2d[i][j] == 0) {
				// Skip this print
			}
			else {
				cout << "[" << i * base << "] * "
					<< "[" << j * base << "] = "
					<< grid2d[i][j] << "\n";
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	// Hold System
	system("pause");
}