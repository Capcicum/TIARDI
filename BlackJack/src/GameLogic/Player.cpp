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

Player::Player(Table* table, int money) :
		table(table), money(money), isHitting(true), bettetMoney(0), isReady(false)
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

void Player::wonBettetMoney()
{
	money += bettetMoney*2;
}

void Player::bet(int value)
{
	if(value >= money)
	{
		bettetMoney = money;
		setMoney(0);
		setIsReady(true);
	}
	else
	{
		bettetMoney = value;
		setMoney(money - value);
		setIsReady(true);
	}
	table->update();
}

void Player::giveCard(Card* card)
{
	cards.push_back(card);
}

std::string Player::getCardsNames()
{
	std::string returnString;
	for(auto i = cards.begin(); i != cards.end(); i++)
	{
		returnString.append((*i)->getCardName());
		returnString.append(", ");
	}
	return returnString;
}

void Player::stand() {
	isHitting = false;
	setIsReady(true);
	table->update();
}

int Player::getCardsTotalValue()
{
	int total = 0;
	for(auto i = cards.begin(); i != cards.end(); i++)
	{
		total += (*i)->getValue();
	}
	bool containsAce = false;
	for (auto iter = cards.begin(); iter != cards.end(); ++iter)
	{
		if ((*iter)->getValue() == Card::ACE)
		{
			containsAce = true;
		}
	}
	//if hand contains ace and total is low enough, treat ace as 11
	if (containsAce && total <= 11)
	{
	//add only 10 since we’ve already added 1 for the ace
		total += 10;
	}
	return total;
}

void Player::hit()
{
	setIsReady(true);
	table->update();
}

bool Player::getIsHitting() {
	return isHitting;
}

void Player::clear()
{
	bettetMoney = 0;
	isHitting = true;
	for(auto i = cards.begin(); i != cards.end(); i++)
	{
		delete *i;
	}
	cards.clear();
}

void Player::setIsReady(bool ready)
{
	isReady = ready;
}

bool Player::getIsReady()
{
	return isReady;
}
}

