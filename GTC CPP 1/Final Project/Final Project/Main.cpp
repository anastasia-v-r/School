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
		while (iInput < 2 || iInput > 4) {
			if (iInput < 2) {
				smallBox("Too few players. Please try again");
			}
			else if (iInput > 4) {
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
	for (int k = 0; k < 2; ++k) {
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
			int tempBet;
			clearScreen();
			draw(players, dealer, i);
			smallBox("Place your bet (0 - 100)");
			cin.ignore(1);
			cin >> tempBet;
			while (tempBet < 0 || tempBet > 100) {
				if (tempBet < 0) {
					smallBox("No negative bets, please reenter");
					cin >> tempBet;
				} else if (tempBet > 100) {
					smallBox("Bet too large, please reenter");
					cin >> tempBet;
				}
			}
			players[i].setBet(tempBet);
			clearScreen();
			draw(players, dealer, i);
		}
		// Deal Cards
		for (int i = 0; i < 2; ++i) {
			// Player Draw
			for (int j = 0; j < players.size(); ++j) {
				if (players[j].getBet() == 0) {
					continue;
				}
				players[j].hand[i] = deck.back();
				deck.pop_back();
			}
			// Dealer Draw
			dealer.hand[i] = deck.back();
			if (i == 0) {
				dealer.hand[0].hideCard(false);
			}
			deck.pop_back();
		}
		// Player Action
		for (int i = 0; i < players.size(); ++i) {
			string sChoice;
			char cChoice;
			int iChoice;
			if (players[i].getBet() == 0) { // Skip no bet players
				continue;
			} else {
				clearScreen();
				draw(players, dealer, i);
				if (dealer.hand[1].getValue() == 1) { // Insurance
					smallBox("Would you like to take insurace? (y/n)");
					cin.ignore(1);
					cin.get(cChoice);
					cChoice = toupper(cChoice); // Input Validation
					while (cChoice != 'Y' && cChoice != 'N') {
						smallBox("Invalid input, try again");
						cin.ignore(1);
						cin.get(cChoice);
						cChoice = toupper(cChoice);
					}
					if (cChoice = 'Y') { // Get insurance amount
						smallBox("How much insuracne would you like to place?");
						cin >> iChoice;
						while (iChoice < 0 || iChoice >(players[i].getBet() / 2)) {
							if (iChoice < 0) {
								smallBox("Too small, place again");
								cin >> iChoice;
							} else if (iChoice > (players[i].getBet() / 2)) {
								smallBox("Too large, place again");
								cin >> iChoice;
							}
						}
						players[i].setInsur(iChoice);
					}
				}
				smallBox("What would you like to do? (Hit/Stand/Double/Split/Surrender)");
				cin.ignore(1);
				getline(cin, sChoice);
				upString(sChoice);
				while (sChoice != "HIT" && sChoice != "STAND" && sChoice != "DOUBLE" && sChoice != "SPLIT" && sChoice != "SURRENDER") {
					smallBox("Invalid input, try again");
					cin.ignore(1);
					getline(cin, sChoice);
					upString(sChoice);
				}
			}
		}
	}
	system("pause");
}

/* TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
1. Betting [DONE]
2. Hit
3. Stand
4. Double Down
5. Split a pair
6. Insurance
*/ 