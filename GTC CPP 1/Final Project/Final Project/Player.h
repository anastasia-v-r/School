#pragma once
#include <vector>
#include <string>

class Player
{
private:
// In-Game
	std::vector<Card> hand;
	int bet;
// Account
	int wins;
	int losses;
	std::string name;
	int bank;

public:
	Player();
	~Player();
};

