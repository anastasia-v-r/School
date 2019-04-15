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
	bool stand = false;
// Account
	int wins;
	int losses;
	std::string name;
	int bank;

public:
	// Misc
	std::vector<Card> hand;
	std::vector<Card> hand2;
	// Getters
	bool isDeal() const;
	int getBet() const;
	std::string getName() const;
	int getBal() const;
	int getWins() const;
	int getLoss() const;
	int getInsur() const;
	bool getStand() const;
	// Setters
	void setStand(bool);
	void setInsur(int);
	void makeDeal(bool);
	void setBet(int);
	void setBal(int);
	// Constructor
	Player(std::string, int, int, int);
	// Destructor
	~Player();
};

