#include "Player.h"
#include <string>

std::string Player::getName() const {
	return name;
}

int Player::getBal() const {
	return bank;
}

int Player::getWins() const {
	return wins;
}

int Player::getLoss() const {
	return losses;
}

bool Player::isDeal() const {
	return dealer;
}

void Player::setBal(int val) {
	bank = val;
}

int Player::getBet() const {
	return bet;
}

int Player::getBet2() const {
	return bet2;
}

void Player::setBet(int uBet) {
	bet = uBet;
}

void Player::setBet2(int uBet) {
	bet2 = uBet;
}

void Player::makeDeal(bool is) {
	dealer = is;
}

void Player::setInsur(int val) {
	insurance = val;
}

int Player::getInsur() const {
	return insurance;
}

bool Player::getStand() const {
	return stand;
}

void Player::setStand(bool isStand) {
	stand = isStand;
}

void Player::setHands(int val) {
	hands = 2;
}

int Player::getHands() const {
	return hands;
}

Player::Player(std::string namE, int banK, int winS, int losS){
	name = namE;
	bank = banK;
	wins = winS;
	losses = losS;
}

Player::~Player(){

}
