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
			std::cin >> prog;
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
	bool prog = pullData(file);
	if (prog) {
		std::cout << "Please enter the path for your output file.\n";
		std::getline(std::cin, sTemp);
		output.open(sTemp, std::ios::out);
		for (int i = 0; i < file.size(); ++i) {
			std::cout << "[" << file[i] << "]";
		}
		for (int i = 0; i < file.size(); ++i) {
			std::string;
		}
	}
	else {
		std::cout << "Encryption unsuccessful, returning to main menu...\n";
	}
}

//void decrypt(std::vector<char> vec) {
//	for (int i = 0; i < vec.size; i += 3) {
//		for (int j = i; j < i + 3; ++j) {
//
//		}
//	}
//}