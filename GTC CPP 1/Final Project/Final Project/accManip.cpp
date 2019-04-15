#include "accManip.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include "customIO.h"

void pullAcc(std::ifstream& plracc, std::vector<Player>& plr) {
	std::string name;
	int bank;
	int wins;
	int loss;
	plracc >> name >> bank >> wins >> loss;
	plr.push_back(Player{ name, bank, wins, loss });
}

void makeAcc(std::string path, std::vector<Player>& plr) {
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
	plr.push_back(Player{ accName, balance, 0, 0 });
}

void updateAcc(std::string path, Player plr) {
	std::fstream outputFile;
	outputFile.open((path + plr.getName() + "-Acc.txt"), std::ios::out);
	outputFile << plr.getName();
	outputFile << plr.getBal();
	outputFile << plr.getWins();
	outputFile << plr.getLoss();
}

// how to use updateAcc, updateAcc(filePath, players[i]);
