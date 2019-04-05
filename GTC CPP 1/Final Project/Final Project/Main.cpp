// Includes and Usings
#include <iostream>
using std::cout; using std::cin;
#include <string>
using std::string;
#include "customWait.h"
#include "customIO.h"
#include "resources.h"
// Variables and Data
bool playing = true;
string sInput;
char cInput;

int main() {
	// Welcome Screen
	menuScreen(menuText);
	wait(2000);
	// Mode Select
	clearScreen();
	smallBox("What mode would you like to play? (PVP/PVE)");
	getline(cin, sInput);
	upString(sInput);
	while (sInput != "PVP" && sInput != "PVE") {
		smallBox("Invalid input, please put PVP or PVE");
		getline(cin, sInput);
		upString(sInput);
	}
	// Account Select
	while (playing) {

	}
	system("pause");
}