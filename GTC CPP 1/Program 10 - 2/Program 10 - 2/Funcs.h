// Includes
#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "Structs.h"

// Funcs
void editVec(std::vector<speaker>& vec, int element) {
	float tempF;
	std::string tempS;
	std::cout << "Please enter the name\n";
	std::cin >> tempS;
	while (tempS.size() > 13 || tempS.size() < 0) {
		if (tempS.size() > 13) {
			std::cout << "Name is too long\n";
		}
		else {
			std::cout << "Name is too short\n";
		}
		std::cin >> tempS;
	}
	vec[element].name = tempS;
	std::cout << "Please enter the phone number [e.g. 555-555-5555]\n";
	std::cin >> tempS;
	while (tempS.size() != 12) {
		std::cout << "Phone number format invalid, please try again\n";
		std::cin >> tempS;
	}
	std::cout << "Please enter the topic\n";
	std::cin >> tempS;
	while (tempS.size() < 0 || tempS.size() > 9) {
		std::cout << "Invalid topic size\n";
		std::cin >> tempS;
	}

	std::cout << "Please enter the fee\n";
	std::cin >> tempF;
	while (tempF < 0 || tempF> 999.99) {
		std::cout << "Please enter a value between and including [999.99 - 0]\n";
		std::cin >> tempF;
	}
	vec[element].fee = tempF;
}

void fillVec(std::vector<speaker>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		editVec(vec, i);
	}
}

void readVec(std::vector<speaker> vec) {
	std::cout << "+--------------------------------------------------+\n";
	std::cout << "|                 List of speakers                 |\n";
	std::cout << "+---------------+--------------+-----------+-------+\n";
	std::cout << "|     Names     | Phone Number |   Topic   |  Fee  |\n";
	std::cout << "+---------------+--------------+-----------+-------+\n";
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << "| " << std::setw(13) << std::left << vec[i].name << " | " << std::setw(12) << std::left << vec[i].phone << " | " << std::setw(9) << std::left << vec[i].topic 
		<< " |$" << std::setw(6) << std::showpoint << std::setprecision(2) << std::fixed << vec[i].fee << "|\n";
		if (i == (vec.size() - 1)) {
			std::cout << "+---------------+--------------+-----------+-------+\n";
		}
		else {
			std::cout << "|               |              |           |       |\n";
		}
	}
}

void exit() {
	for (int count = 5; count > 0; --count) {
		std::cout << "Exiting in " << count;
		Sleep(500);
		std::cout << ".";
		Sleep(500);
		std::cout << ".\n";

	}
}

