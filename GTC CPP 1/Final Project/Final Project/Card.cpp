#include "Card.h"

int Card::getValue() const {
	return value;
}

char Card::getSuit() const {
	return suit;
}

bool Card::isFace() const {
	return faceUp;
}

Card::Card(int val, char su) {
	suit = su;
	value = val;
}

Card::~Card() {

}
