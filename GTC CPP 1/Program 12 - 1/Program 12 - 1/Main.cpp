#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "funcs.h"

bool progIn, progOut;
char choice;
std::string option;

int main() {
	
	do {
		std::cout << "+---------------------+\n"
				  << "|Would like to :      |\n"
				  << "+---------------------+\n"
				  << "|(A) Encrypt a file.  |\n"
				  << "|(B) Cypher a file.   |\n"
				  << "|(D) Exit the program.|\n"
				  << "+---------------------+\n\n";
		
		std::cin.get(choice);
		choice = toupper(choice);
		if (choice == 'A') {
			progIn = encrypt();
			option = "Encryption";
		} else if (choice == 'B') {
			progIn = decrypt();
			option = "Cypher";
		} else if (choice == 'C') {

		} else { 
			break;
		}
		if (progIn) {
			std::cout << "+--------------------------------------+\n"
					  << "|" << std::setw(10) << option << " was completed successfully.|\n"
					  << "+--------------------------------------+\n\n";
		}
		std::cout << "+-------------------------------------------+\n"
				  << "|Would you like to do something else? (y/n)?|\n"
				  << "+-------------------------------------------+\n\n";
		
		std::cin >> progOut;
		progOut = tolower(progOut);
	} while (progOut);

	std::cin.ignore(1000);

}

/*

Program 1:

File encryption is the science of writing the contents of a file in a secret code.
Your encryption program should work like a filter, reading the contents of one file, 
modifying the data into a code, and then writing the coded contents out to a second file. 
The second file will be a version of the first file, but written in a secret code.
Although there are complex encryption techniques, you should come up with a simple one of your own.
For example, you could read the first file one character at a time, and add 10 to the ASCII code of each character before it is written to the second file.

To test your encryption, write a second program that decrypts the file produced by your encryption program. 
The decryption program should read the contents of the coded file, restore the data to its original state, and write it to a 3rd file.

You will need two VS or XCode projects to do this. Copy the contents from the encrypted output file to the input file for the decryption program to use.
*/