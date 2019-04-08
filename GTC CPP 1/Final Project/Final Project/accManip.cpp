#include "accManip.h"
#include <iostream>
#include <fstream>
#include <string>
#include "customIO.h"

void pullAcc(std::ifstream& plracc) {

}

void makeAcc(std::string path) {
	std::fstream outputFile;
	smallBox("Please enter an account name");
	std::string accName;
	getline(std::cin, accName);
	outputFile.open((path + accName + "-Acc.txt"), std::ios::out);
	outputFile << accName;
	smallBox("Please enter your starting balance than 10 grand");
	int balance;
	std::cin >> balance;
	while (balance < 0 || balance > 10000) {
		smallBox("Invalid amount, please try again");
		std::cin >> balance;
	}
	outputFile << balance;
	outputFile << 0;
	outputFile << 0;
}

void updateAcc() {

}
