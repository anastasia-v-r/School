#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>
#include "Player.h"
#include "game.h"

void draw(Player plr, Player dlr) {
	//      "+--------------------------------------------------------------------------------------------+";//
	cout << "\n";																							 //
	cout << "Name:" << setw(10) << plr.getName() << " Bal:" << setw(8) << plr.getBal() << "\n";									 //
	cout << "Bet:" << plr.getBet() << "\n";																							 //
	cout << "\n";																							 //
	cout << "\n";																							 //
	cout << "                                       Dealer \n";												 //
	cout << "                              +----------+ +----------+                                       ";//
	cout << "                              |" << dlr.hand[0].getSuit() << dlr.hand[0].getValue() << "        | |" << dlr.hand[1].getSuit() << dlr.hand[1].getValue() << "        |\n";
	cout << "							   |          | |          |                                       ";//
	cout << "							   |          | |          |                                       ";//
	cout << "							   |          | |          |                                       ";//
	cout << "							   |          | |          |                                       ";//
	cout << "							   |          | |          |                                       ";//
	cout << "							   +----------+ +----------+                                       ";//
	cout << "\n";																							 //
	cout << "\n";																							 //
	cout << "\n";																							 //
	cout << "\n";																							 //
	cout << "                                    Player (You) \n";											 //
	cout << "                              +----------+ +----------+";                                       //
	cout << "                              |" << plr.hand[0].getSuit() << plr.hand[0].getValue() << "        | |" << plr.hand[1].getSuit() << plr.hand[1].getValue() << "        |\n"; 																										//
	cout << "							   |          | |          |									   ";//
	cout << "							   |          | |          |									   ";//
	cout << "							   |          | |          |									   ";//
	cout << "							   |          | |          |									   ";//
	cout << "							   |          | |          |									   ";//
	cout << "							   +----------+ +----------+									   ";//
	cout << "\n";																							 //
	cout << "\n";																							 //
}																											
