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
Player::~Player()
{
	clearCards();
}

void Player::clearForNewGame()
{
	setBettetMoney(0);
	setIsHitting(true);
	clearCards();
}

void Player::wonBettetMoney()
{
	int won = getMoney() + getBettetMoney()*2;
	setMoney(won);
}

int Player::getMoney()
{
	return money;
}

void Player::setMoney(int value)
{
	money = value;
}

void Player::setIsReady(bool ready)
{
	isReady = ready;
}

bool Player::getIsReady()
{
	return isReady;
}

int Player::getBettetMoney()
{
	return bettetMoney;
}

void Player::setBettetMoney(int value)
{
	bettetMoney = value;
}

bool Player::getIsHitting()
{
	return isHitting;
}

void Player::setIsHitting(bool hitting)
{
	isHitting = hitting;
}

Table* Player::getTable()
{
	return table;
}

void Player::setTable(Table* t)
{
	table = t;
}

//Protected

void Player::bet(int value)
{
	if(value >= getMoney())
	{
		setBettetMoney(getMoney());
		setMoney(0);
		setIsReady(true);
	}
	else
	{
		setBettetMoney(value);
		int moneyLeft = getMoney()-value;
		setMoney(moneyLeft);
		setIsReady(true);
	}
	getTable()->update();
}



void Player::stand()
{
	setIsHitting(false);
	setIsReady(true);
	getTable()->update();
}

void Player::hit()
{
	setIsReady(true);
	getTable()->update();
}

}

