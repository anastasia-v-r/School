#pragma once
#include <vector>
#include <string>
#include "Card.h"

class Player
{
private:
// In-Game
	int bet;
	bool dealer;
// Account
	int wins;
	int losses;
	std::string name;
	int bank;

public:
	std::vector<Card> hand;
	std::string getName() const;
	bool isDeal() const;
	void makeDeal(bool);
	int getBet() const;
	void setBet(int);
	int getBal() const;
	int getWins() const;
	int getLoss() const;
	void setBal(int);
	Player(std::string, int, int, int);
	~Player();
};

