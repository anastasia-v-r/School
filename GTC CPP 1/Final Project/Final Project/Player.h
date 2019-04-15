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
	int bet2 = 0;
	bool dealer;
	bool stand = false;
	int hands = 1;
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
	int getBet2() const;
	std::string getName() const;
	int getBal() const;
	int getWins() const;
	int getLoss() const;
	int getInsur() const;
	bool getStand() const;
	int getHands() const;
	// Setters
	void setHands(int);
	void setStand(bool);
	void setInsur(int);
	void makeDeal(bool);
	void setBet(int);
	void setBet2(int);
	void setBal(int);
	// Constructor
	Player(std::string, int, int, int);
	// Destructor
	~Player();
};

