// Includes / Usings
#include <iostream>
using std::cin; using std::cout;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include "funcs.h"
// Variables
char goAgain, choice;
bool success;
string operation;
// Entry Point
int main() {
	do {
		// Ask user for what they wish to do
		cout << "+---------------------+\n"
			 << "| Would you like to:  |\n"
			 << "+---------------------+\n"
			 << "|(A) Encrypt a file.  |\n"
			 << "|(B) Cypher a file.   |\n"
			 << "|(C) Exit the program.|\n"
			 << "+---------------------+\n\n";
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		cin.get(choice);
		choice = toupper(choice);
		// Use input to choose action
		if (choice == 'A') {
			success = encrypt();
			operation = "encryption";
		} else if (choice == 'B') {
			success = cypher();
			operation = "cypher";
		} else {
			break;
		}
		// Report on the success of file operations
		if (success) {
			cout << "+-------------------------------------------+\n"
				 << "|File " << setw(10) << operation << " was completed successfully.|\n"
				 << "+-------------------------------------------+\n\n";
		} else {
			
		}
		cout << "+-------------------------------------------+\n"
			 << "|Would you like to do something else? (y/n)?|\n"
			 << "+-------------------------------------------+\n\n";
		std::cin.ignore();
		std::cin.get(goAgain);
		goAgain = tolower(goAgain);
	} while (goAgain == 'y');
	system("pause");
}