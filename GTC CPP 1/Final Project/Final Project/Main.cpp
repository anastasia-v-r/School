// Includes and Usings
#include <iostream>
using std::cout; using std::cin;
#include <string>
using std::string;
#include <fstream>
#include <filesystem>
#include "customWait.h"
#include "customIO.h"
#include "resources.h"
#include "classes.h"
#include "accManip.h"
// Variables and Data
string accPath = std::filesystem::current_path().string() + "\\accs\\";
bool playing = true;
string sInput;
char cInput;
int iInput, plrAm;
std::vector<Player> players;
int main() {
	// File check
	if (std::filesystem::is_directory(accPath)) {
		// smallBox("Success");
		// smallBox(accPath);
	} else {
		smallBox("Failure to access accs folder");
		// smallBox(accPath);
		exiting();
		return 0;
	}
	// Welcome Screen
	menuScreen(menuText);
	wait(2000);
	// Mode Select
	clearScreen();
	smallBox("What mode would you like to play? (PVP/PVE)");
	getline(cin, sInput);
	upString(sInput);
	// Input Validation
	while (sInput != "PVP" && sInput != "PVE") {
		smallBox("Invalid input, please put PVP or PVE");
		getline(cin, sInput);
		upString(sInput);
	}
	if (sInput == "PVP") {
		smallBox("How many players?");
		cin >> iInput;
		// Input Validation
		while (iInput < 2 || iInput > 6) {
			if (iInput < 2) {
				smallBox("Too few players. Please try again");
			}
			else if (iInput > 6) {
				smallBox("Too many players. Please try again");
			}
			cin.ignore(1);
			cin >> iInput;
		}
		plrAm = iInput;
	} else if (sInput == "PVE") {
		plrAm = 1;
	} else {
		smallBox("A critical error has been encountered, exiting");
		exiting();
		return 0;
	}
	// Account Select
	for (int i = 0; i < plrAm; ++i) {
		bool existing;
		smallBox(" Player [" + std::to_string(i + 1) + "] : Do you already have an account? (y/n)");
		cin.get(cInput);
		cInput = toupper(cInput);
		// Input Validation
		while (cInput != 'Y' && cInput != 'N') {
			smallBox("That input was invalid, please try again");
			cin.ignore(1);
			cin.get(cInput);
			cInput = toupper(cInput);
		}
		if (cInput == 'Y') {
			std::ifstream plrAcc;
			smallBox("Please enter your account name");
			getline(cin, sInput);
			plrAcc.open(accPath + sInput + "-Acc.txt");
			if (plrAcc) {
				pullAcc(plrAcc); // Not yet implemented
			} else {
				smallBox("Account does not exist, creating now");
			}
		} else if (cInput == 'N') {
			makeAcc(accPath);

		} else {
			smallBox("A critical error has been encountered, exiting");
			exiting();
			return 0;
		}
	}
	// Game Loop
	while (playing) {

	}
	system("pause");
}