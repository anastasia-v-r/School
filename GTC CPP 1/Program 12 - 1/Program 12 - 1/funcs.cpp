#pragma once
#include "funcs.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool pullData(std::vector<char>& file) {
	std::string filePath;
	std::fstream input;
	char prog, i;
	do {
		std::cout << "Please input your file path.\n";
		std::cin.ignore();
		std::getline(std::cin, filePath);
		input.open(filePath, std::ios::in);
		if (input) {
			while (input.get(i)) {
				file.push_back(i);
			}
			return true;
		}
		else {
			std::cout << "Error opening file!\n"
				   	  << "Would you like to try again? (y/n)\n";
			std::cin.get(prog);
			prog  = tolower(prog);
			if (prog == 'n') {
				return false;
			}
		}
	} while (prog == 'y');
}

bool encrypt() {
	std::vector<char> file;
	std::string sTemp;
	std::fstream output;
	bool done = false;
	bool prog = pullData(file);
	if (prog) {
		do {
			std::cout << "Please enter the path for your output file.\n";
			std::getline(std::cin, sTemp);
			output.open(sTemp, std::ios::out);
			if (output) {
				for (int i = 0; i < file.size(); ++i) {
					int a = file[i];
					sTemp = a;
					int size = (sizeof(sTemp) / sizeof(sTemp[0]));
					for (int j = 0; j < (size - 1); j++) {
						if (size > 1) {
							if (j == 1 && j == 2) {
								std::cout << "/";
							}
						}
						int b = (int)sTemp[j];
						std::cout << b;
					}
				}
				std::cout << "\n";
				return true;
			} else {
				std::cout << "Error creating file!\n";
			}
		} while (!done);
	}
	else {
		std::cout << "Encryption unsuccessful, returning to main menu...\n";
		return false;
	}
}

bool decrypt() {
	return true;
}