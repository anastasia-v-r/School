#include "customIO.h"
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout;
#include <vector>

void smallBox(const string& msg) {
	for (int i = 0; i < (msg.length() + 4); ++i) {
		cout << "#";
	}
	cout << "\n";
	cout << "# " << msg << " #\n";
	for (int i = 0; i < (msg.length() + 4); ++i) {
		cout << "#";
	}
	cout << "\n";
}

void upString(string& msg) {
	for (int i = 0; i < msg.length(); ++i) {
		msg[i] = toupper(msg[i]);
	}
}

void menuScreen(std::vector<string> msg) {
	for (int i = 0; i < msg.size(); ++i) {
		cout << msg[i];
	}
}

void clearScreen() {
	for (int i = 0; i < 100; ++i) {
		cout << "\n";
	}
}