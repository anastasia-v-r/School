// Includes n Usings
#include <iostream>
using std::cout; using std::cin;
#include <vector>
using std::vector;
#include <chrono>
#include <thread>
// Variables
vector<vector<vector<int>>> grid3d;
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
		cout << "+----------------------------------------+\n"
			 << "| Invalid input, please enter an integer |\n"
			 << "+----------------------------------------+\n";
		cin >> base;
	}
	// Get length from user
	cout << "+----------------------------------------+\n"
		 << "| How long do you want each array to be? |\n"
		 << "+----------------------------------------+\n";
	cin >> length;
	// Validate input
	while (!(length > 0 && length < INT_MAX)) {	
		cout << "+-----------------------------------------------+\n"
			<< "| Invalid input, please enter a positive integer |\n"
			<< "+------------------------------------------------+\n";
		cin >> length;
	}
	// Generate cube
	grid3d.resize(length, vector<vector<int>>(length, vector<int>(length)));
	// Fill cube
	for (int i = 1; i < length; ++i) {
		for (int j = 1; j < length; ++j) {
			for (int k = 1; k < length; ++k) {
				grid3d[i][j][k] = ((i * base)*(j * base)*(k * base));
			}
		}
	}
	// Print cube
	for (int i = 1; i < length; ++i) {
		for (int j = 1; j < length; ++j) {
			for (int k = 1; k < length; ++k) {
				if (grid3d[i][j][k] == 0) {
					// Skip this print
				} else {
					cout << "[" << i * base << "] * "
						 << "[" << j * base << "] * "
						 << "[" << k * base << "] = "
						 << grid3d[i][j][k] << "\n";
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
	}
	// Hold System
	system("pause");
}