#pragma once
// Includes 
#include "funcs.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// Read File
bool pullData(std::vector<char>& file) {
	// Variables
	std::string filePath; // Store file path of input file
	std::fstream input; // Fstream for using that file path
	char progress, getChar; 
	do {
		std::cout << "+----------------------------+\n"
				  << "|Please input your file path.|\n"
				  << "+----------------------------+\n\n";
		std::cin.ignore();
		std::getline(std::cin, filePath); // Get file path from user
		input.open(filePath, std::ios::in);
		if (input) { // Pull file into into 
			while (input.get(getChar)) {
				file.push_back(getChar);
			}
			return true;
		}
		else {
			std::cout << "+----------------------------------+\n"
					  << "|       Error opening file!        |\n"
					  << "+----------------------------------+\n"
				   	  << "|Would you like to try again? (y/n)|\n"
					  << "+----------------------------------+\n\n";
			std::cin.get(progress);
			progress  = tolower(progress);
			if (progress == 'n') {
				return false;
			}
		}
	} while (progress == 'y');
}
// Encrypt
bool encrypt() {
	std::vector<char> file;
	std::string sTemp;
	std::fstream output;
	char key;
	bool done = false;
	bool prog = pullData(file);
	if (prog) {
		do {
			std::cout << "+-------------------------------------------+\n"
					  << "|Please enter the path for your output file.|\n"
					  << "+-------------------------------------------+\n\n";
			std::getline(std::cin, sTemp);
			output.open(sTemp, std::ios::out);
			std::cout << "+----------------------+\n"
					  << "|Please enter your key.|\n"
					  << "+----------------------+\n\n";
			std::cin.get(key);
			if (output) {
				for (int i = 0; i < file.size(); ++i) {
					file[i] ^= key;
					output << file[i];
				}
				std::cout << "\n";
				return true;
			} else {
				std::cout << "+--------------------+\n"
						  << "|Error creating file!|\n"
						  << "+--------------------+\n\n";
			}
		} while (!done);
	}
	else {
		std::cout << "+--------------------------------------------------+\n"
				  << "|Encryption unsuccessful, returning to main menu...|\n"
				  << "+--------------------------------------------------+\n\n";
		return false;
	}
}

// Encrypt
bool cypher() {
	std::vector<char> file;
	std::string sTemp;
	std::fstream output;
	char key;
	bool done = false;
	bool prog = pullData(file);
	if (prog) {
		do {
			std::cout << "+-------------------------------------------+\n"
					  << "|Please enter the path for your output file.|\n"
					  << "+-------------------------------------------+\n\n";
			std::getline(std::cin, sTemp);
			output.open(sTemp, std::ios::out);
			std::cout << "+----------------------+\n"
					  << "|Please enter your key.|\n"
					  << "+----------------------+\n\n";
			std::cin.get(key);
			if (output) {
				for (int i = 0; i < file.size(); ++i) {
					file[i] ^= key;
					output << file[i];
				}
				std::cout << "\n";
				return true;
			}
			else {
				std::cout << "+--------------------+\n"
						  << "|Error creating file!|\n"
						  << "+--------------------+\n\n";
			}
		} while (!done);
	}
	else {
		std::cout << "+----------------------------------------------+\n"
				  << "|Cypher unsuccessful, returning to main menu...|\n"
		 		  << "+----------------------------------------------+\n\n";
		return false;
	}
}