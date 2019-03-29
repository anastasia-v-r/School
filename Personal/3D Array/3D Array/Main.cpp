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
char goOn;
// Entry Point
int main() {
	do {
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
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				for (int k = 0; k < length; ++k) {
					grid3d[i][j][k] = (((i + 1) * base)*((j + 1) * base)*((k + 1) * base));
				}
			}
		}
		// Print cube
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				for (int k = 0; k < length; ++k) {
					if (grid3d[i][j][k] == 0) {
						// Skip this print
					}
					else {
						cout << "[" << (i + 1) * base << "] * "
							 << "[" << (j + 1) * base << "] * "
						 	 << "[" << (k + 1) * base << "] = "
							 << grid3d[i][j][k] << "\n";
					}
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
				}
			}
		}
		// Ask user if they would like to try again
		cout << "+---------------------------------------+\n"
			 << "| Would you like to go again? ( y / n ) |\n"
			 << "+---------------------------------------+\n";
		cin >> goOn;
		goOn = tolower(goOn);
		// Validate input
		while (goOn != 'y' && goOn != 'n') {
			cout << "+----------------------------------------------+\n"
				 << "| Invalid input, please enter a valid character |\n"
				 << "+-----------------------------------------------+\n";
			cin >> goOn;
			goOn = tolower(goOn);
		}
		// Hold System
		system("pause");
	} while (goOn == 'y');	
}