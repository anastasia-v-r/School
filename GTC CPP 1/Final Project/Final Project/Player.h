#pragma once
#include <vector>
#include <string>
#include "Card.h"

class Player
{
private:
// In-Game
	int insurance = 0;
	int bet = 0;
	bool dealer;
// Account
	int wins;
	int losses;
	std::string name;
	int bank;

public:
	// Misc
	std::vector<Card> hand;
	// Getters
	bool isDeal() const;
	int getBet() const;
	std::string getName() const;
	int getBal() const;
	int getWins() const;
	int getLoss() const;
	int getInsur() const;
	// Setters
	void setInsur(int);
	void makeDeal(bool);
	void setBet(int);
	void setBal(int);
	// Constructor
	Player(std::string, int, int, int);
	// Destructor
	~Player();
};

