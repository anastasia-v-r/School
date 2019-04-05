#include "customIO.h"
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout;

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