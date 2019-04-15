#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "customIO.h"
#include "Player.h"
#include "game.h"

void draw(std::vector<Player> plrs, Player dlr, int curr) {
	       "+--------------------------------------------------------------------------------------------+";
	cout << "\n";																							 
	cout << "Name:" << setw(10) << plrs[curr].getName() << " Bal:" << setw(8) << plrs[curr].getBal() << "\n";									 
	cout << "Bets:";
	for (int i = 0; i < plrs.size(); ++i) {
		cout << "[P" << i + 1 << "]" << plrs[i].getBet();
		if (i < (plrs.size() - 1)) {
			cout << " | ";
		}
	}
	cout << "\n";
	cout << "Cards:";
	for (int i = 0; i < plrs.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			cout << "P" << i << "[" << plrs[i].hand[j].getSuit() << plrs[i].hand[j].getValue() << "]";
		}
		if (i < (plrs.size() - 1)) {
			cout << " | ";
		}
	}
	if (plrs[curr].hand.size() > 2) {
		cout << "Your Extra Cards: ";
		for (int i = 2; i < plrs[curr].hand.size(); ++i) {
			cout << "[" << plrs[curr].hand[i].getSuit() << plrs[curr].hand[i].getValue() << "]";
		}
		cout << "\n";
	} else {
		cout << "\n";
	}
	cout << "\n";																							 
	cout << "                                       Dealer \n";												 
	cout << "                              +----------+ +----------+                                       ";
	cout << "                              |" << dlr.hand[0].getSuit() << dlr.hand[0].getValue() << "        | |" << dlr.hand[1].getSuit() << dlr.hand[1].getValue() << "        |\n";
	cout << "							   |          | |          |                                       ";
	cout << "							   |          | |          |                                       ";
	cout << "							   |          | |          |                                       ";
	cout << "							   |          | |          |                                       ";
	cout << "							   |          | |          |                                       ";
	cout << "							   +----------+ +----------+                                       ";
	if (dlr.hand.size() > 2) {
		cout << "The Dealers Extra Cards: ";
		for (int i = 2; i < dlr.hand.size(); ++i) {
			cout << "[" << dlr.hand[i].getSuit() << dlr.hand[i].getValue() << "]";
		}
		cout << "\n";
	}
	else {
		cout << "\n";
	}
	cout << "\n";																							 																							 
	cout << "                                    Player (You) \n";											 
	cout << "                              +----------+ +----------+";                                       
	cout << "                              |" << plrs[curr].hand[0].getSuit() << plrs[curr].hand[0].getValue() << "        | |" << plrs[curr].hand[1].getSuit() << plrs[curr].hand[1].getValue() << "        |\n"; 																										
	cout << "							   |          | |          |									   ";
	cout << "							   |          | |          |									   ";
	cout << "							   |          | |          |									   ";
	cout << "							   |          | |          |									   ";
	cout << "							   |          | |          |									   ";
	cout << "							   +----------+ +----------+									   ";																							 
}																											

// Deck Setup
int makeDeck(std::vector<Card>& deck) {
	int seed = std::chrono::system_clock::now().time_since_epoch().count(); // Shuffle Seed
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
				if (j > 10) {
					deck.push_back(Card(10, currSuit));
				}
				else {
					deck.push_back(Card(j, currSuit));
				}

			}
		}
	}
	shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}
