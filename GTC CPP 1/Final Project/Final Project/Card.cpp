#include "Card.h"

int Card::getValue() const {
	if (faceUp) {
		return value;
	}
	else {
		return 0;
	}
}

void Card::setValue(int val) {
	value = val;
}

char Card::getSuit() const {
	if (faceUp) {
		return suit;
	} else {
		return 'X';
	}
}

bool Card::isFace() const {
	return faceUp;
}

void Card::hideCard(bool face) {
	faceUp = face;
}

Card::Card() {

}

Card::Card(int val, char su) {
	suit = su;
	value = val;
}

Card::Card(int val, char su, bool isFace) {
	suit = su;
	value = val;
	faceUp = isFace;
}

Card::~Card() {

}
