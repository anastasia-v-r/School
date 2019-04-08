#pragma once

class Card
{
private:
	int value;
	char suit;
	bool faceUp;
public:
	Card(int, char);
	~Card();
	char getSuit() const;
	int getValue() const;
	bool isFace() const;
};

