// Includes and Usings
#include <iostream>
using std::cout; using std::cin;
#include <string>
using std::string;
#include <algorithm>
#include <random>
#include <fstream>
#include <filesystem>
#include "customWait.h"
#include "customIO.h"
#include "resources.h"
#include "classes.h"
#include "accManip.h"
#include "game.h"
// Variables and Data
string accPath = std::filesystem::current_path().string() + "\\accs\\";
bool playing = true;
string sInput;
char cInput;
int iInput, plrAm;
std::vector<Player> players;
int main() {
	// File check
	if (std::filesystem::is_directory(accPath)) {
		// smallBox("Success");
		// smallBox(accPath);
	} else {
		smallBox("Failure to access accs folder");
		// smallBox(accPath);
		exiting();
		return 0;
	}
	// Welcome Screen
	menuScreen(menuText);
	wait(2000);
	// Mode Select
	clearScreen();
	smallBox("What mode would you like to play? (PVP/PVE)");
	getline(cin, sInput);
	upString(sInput);
	// Input Validation
	while (sInput != "PVP" && sInput != "PVE") {
		smallBox("Invalid input, please put PVP or PVE");
		getline(cin, sInput);
		upString(sInput);
	}
	if (sInput == "PVP") {
		smallBox("How many players?");
		cin >> iInput;
		// Input Validation
		while (iInput < 2 || iInput > 6) {
			if (iInput < 2) {
				smallBox("Too few players. Please try again");
			}
			else if (iInput > 6) {
				smallBox("Too many players. Please try again");
			}
			cin.ignore(1);
			cin >> iInput;
		}
		plrAm = iInput;
	} else if (sInput == "PVE") {
		plrAm = 1;
	} else {
		smallBox("A critical error has been encountered, exiting");
		exiting();
		return 0;
	}
	// Account Select
	for (int i = 0; i < plrAm; ++i) {
		bool existing;
		smallBox(" Player [" + std::to_string(i + 1) + "] : Do you already have an account? (y/n)");
		cin.ignore(1);
		cin.get(cInput);
		cInput = toupper(cInput);
		// Input Validation
		while (cInput != 'Y' && cInput != 'N') {
			smallBox("That input was invalid, please try again");
			cin.ignore(1);
			cin.get(cInput);
			cInput = toupper(cInput);
		}
		if (cInput == 'Y') {
			std::ifstream plrAcc;
			smallBox("Please enter your account name");
			cin.ignore(1);
			getline(cin, sInput);
			plrAcc.open(accPath + sInput + "-Acc.txt");
			if (plrAcc) {
				pullAcc(plrAcc, players); // Not yet implemented
			} else {
				smallBox("Account does not exist");
				smallBox("A critical error has been encountered, exiting");
				exiting();
				return 0;
			}
		} else if (cInput == 'N') {
			makeAcc(accPath, players);
		} else {
			smallBox("A critical error has been encountered, exiting");
			exiting();
			return 0;
		}
	}
	// Deck Setup
	int seed = std::chrono::system_clock::now().time_since_epoch().count(); // Shuffle Seed
	std::vector<Card> deck; // Make deck
	for (int i = 0; i < 4; ++i) { // Outer loop sets suit
		char currSuit;
		switch (i)
		{
		case(0):
			currSuit = '♣';
			break;
		case(1):
			currSuit = '♦';
			break;
		case(2):
			currSuit = '♥';
			break;
		case(3):
			currSuit = '♠';
			break;
		default:
			smallBox("A critical error has been encountered, exiting");
			exiting();
			return 0;
		}
		for (int j = 1; j < 14; ++j) { // Inner loop sets value
			deck.push_back(Card(j, currSuit));
		}
	}
	shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
	// Plr's Setup
	Player dealer("", 0, 0, 0); // Create Dealer
	for (int i = 0; i < players.size(); ++i) { // Setup Players
		for (int j = 0; j < 2; ++j) {
			players[i].hand.push_back(Card(0, '0'));
			players[i].setBet(0);
		}
	}
	for (int i = 0; i < 2; ++i) { // Setup Dealer
		dealer.hand.push_back(Card(0, '0'));
	}
	dealer.makeDeal(true); // Dealer was normal player -> is now Dealer type of player
	// Game Loop
	while (playing) {
		wait(1);
		// Place betts
		for (int i = 0; i < players.size(); ++i) {
			Player currPlr = players[i];
			draw(currPlr, dealer);

		}
		// Dealer turn
	}
	system("pause");
}

/* TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
1. Betting
2. Hit
3. Stand
4. Double Down
5. Split a pair
6. Insurance
*/ 