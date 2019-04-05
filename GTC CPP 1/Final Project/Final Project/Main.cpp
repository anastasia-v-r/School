// Includes and Usings
#include <iostream>
using std::cout; using std::cin;
#include <string>
using std::string;
#include "customIO.h"
// Variables and Data
bool playing = true;
string sInput;
char cInput;

int main() {

	smallBox("What mode would you like to play? (PVP/PVE)");
	getline(cin, sInput);
	upString(sInput);
	while (sInput != "PVP" && sInput != "PVE") {
		smallBox("Invalid input, please put PVP or PVE");
		getline(cin, sInput);
		upString(sInput);
	}

	while (playing) {

	}
	system("pause");
}