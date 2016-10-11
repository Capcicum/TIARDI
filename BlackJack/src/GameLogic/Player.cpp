/*
 * Player.cpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#include <GameLogic/Player.hpp>
#include <sstream>
#include <string>
#include <iostream>

namespace GameLogic {

Player::Player() :
		money(0)
{
	// TODO Auto-generated constructor stub

}

Player::Player(int money) :
		money(money)
{

}

int Player::getMoney()
{
	return money;
}

void Player::setMoney(int value)
{
	money = value;
}

void Player::bet(int value)
{

}

void Player::getCard()
{

}

/*void Player::makeAcesOnes() {
	for (size_t i = 0; i < cards.size(); i++) {
		if (cards[i] == 11) {
			cards.at(i) = 1;
		}
	}
}*/

/*void Player::giveCard (int card) {
	cards.push_back(card);
}*/

/*std::string Player::getCards() {
	std::string cardString = "";
	std::cout << "hello" << std::endl;
	for (size_t i = 0; i < cards.size(); i++) {
		std::cout << cards.size() << " size" << std::endl;
		std::cout << cards[i] << std::endl;
		cardString.append(intToString(cards[i]));
		if (i != cards.size() - 1) {
			cardString.append(", ");
		}
	}
	return cardString;
}*/

void Player::stick() {
	stickFlag = true;
}

int Player::getCardsTotalValue() {
	/*int sum = 0;
	for (size_t i = 0; i < cards.size(); i++) {
		sum += cards[i];
	}*/
	//return sum;
}

bool Player::getHitStick() {
	return stickFlag;
}

/*std::string Player::intToString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}*/

}

