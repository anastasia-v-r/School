#include "customIO.h"
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout;
#include <vector>
#include "customWait.h"

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

void exiting() {
	wait(1000);
	cout << "\n[Exiting]\n";
	for (int i = 3; i > 0; --i) {
		cout << i;
		for (int j = 0; j < 3; ++j) {
			cout << ".";
			wait(1000 / 3);
		}
		cout << "\n";
	}
}
