#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>
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
	cout << "\n";
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
	cout << "\n";																							 																						 
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
