#pragma once

class Card
{
private:
	int value;
	int hiddenVal;
	int hiddenSuit;
	char suit;
	bool faceUp = true;
public:
	Card(int, char);
	Card(int, char, bool);
	~Card();
	char getSuit() const;
	int getValue() const;
	void setValue(int);
	bool isFace() const;
	void hideCard(bool);
};

