// Includes / Usings
#include <iostream>
using std::cin; using std::cout;
// Variables
bool goAgain, success;
char choice;
// Entry Point
int main() {
	do {
		// Ask user for what they wish to do
		cout << "+---------------------+\n"
			 << "|Would like to :      |\n"
			 << "+---------------------+\n"
			 << "|(A) Encrypt a file.  |\n"
			 << "|(B) Cypher a file.   |\n"
			 << "|(C) Encode a file.   |\n"
			 << "|(D) Decode a file.   |\n"
			 << "|(E) Exit the program.|\n"
			 << "+---------------------+\n\n";
		cin.get(choice);
		choice = toupper(choice);
		// Use input to choose action
		if (choice == 'A') {

		} else if (choice == 'B') {

		} else if (choice == 'C') {

		} else if (choice == 'D') {

		} else {
			break;
		}
		// Report on the success of file operations
		if (success) {

		} else {
			
		}


	} while (goAgain == true);
	system("pause");
}



cout << "+--------------------------------------+\n"
<< "|" << std::setw(10) << option << " was completed successfully.|\n"
<< "+--------------------------------------+\n\n";


cout << "+-------------------------------------------+\n"
<< "|Would you like to do something else? (y/n)?|\n"
<< "+-------------------------------------------+\n\n";