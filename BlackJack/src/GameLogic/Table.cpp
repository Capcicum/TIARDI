/*
 * Table.cpp
 *
 *  Created on: 12. okt. 2016
 *      Author: Andersen
 */

#include <GameLogic/Table.hpp>
#include <iostream>
#include <windows.h>

namespace GameLogic {


	Table::Table() :
			phase(BETTING)
	{
		dealer = new Dealer();
		deck = new Deck(1);
	}

	void Table::addNewPlayer(Player* player)
	{
		players.push_back(player);
	}

	void Table::deletePlayer(Player* player)
	{
		auto iter = find(players.begin(), players.end(), player);
		if(iter != players.end())
		{
			delete *iter;
			players.erase(iter);
		}
	}

	void Table::startNewGame()
	{

	}

	void Table::dealNewRound()
	{

		dealer->giveCard(deck->getCard());
		for(auto i = players.begin(); i != players.end(); i++)
		{
			(*i)->giveCard(deck->getCard());
			(*i)->giveCard(deck->getCard());
		}
	}

	void Table::update()
	{
		switch(phase)
		{
		case BETTING:
			betting();
			break;
		case DEALING:
			dealing();
			break;
		case HOUSEPLAYING:
			housePlaying();
			break;
		case EXIT:
			exit();
			break;
		}
	}

	void Table::betting()
	{
		for(auto i = players.begin(); i != players.end(); i++)
		{
			if((*i)->getIsReady() == false)
			{
				return;
			}
		}
		Sleep(1000);
		dealNewRound();
		for(auto i = players.begin(); i != players.end(); i++)
		{
			(*i)->update(Player::DEAL);
			(*i)->setIsReady(false);
		}
		phase = DEALING;
	}

	void Table::dealing()
	{
		for(auto i = players.begin(); i != players.end(); i++)
		{
			if(!(*i)->getIsReady())
			{
				return;
			}
		}
		for(auto i = players.begin(); i != players.end(); i++)
		{
			if((*i)->getIsHitting())
			{
				(*i)->giveCard(deck->getCard());
				(*i)->update(Player::NEWCARD);
				return;
			}
		}
		for(auto i = players.begin(); i != players.end(); i++)
		{
			(*i)->setIsReady(false);
		}
		phase = HOUSEPLAYING;
		Sleep(2);
		update();

	}

	void Table::housePlaying()
	{
		dealer->giveCard(deck->getCard());
		for(auto i = players.begin(); i != players.end(); i++)
		{
			(*i)->update(Player::DEALERSECONDCARD);
		}
		Sleep(1000);
		while(dealer->getIsHitting())
		{
			dealer->giveCard(deck->getCard());
			for(auto i = players.begin(); i != players.end(); i++)
			{

				(*i)->update(Player::DEALERNEWCARD);
			}
			Sleep(1000);
		}
		for(auto i = players.begin(); i != players.end(); i++)
		{

			(*i)->update(Player::DEALERSTAND);
		}
		phase = EXIT;
		Sleep(1000);
		update();
	}

void Table::exit() {
	int dealerValue = dealer->getCardsTotalValue();
	if (dealerValue > 21) {
		for (auto i = players.begin(); i != players.end(); i++) {
			if ((*i)->getCardsTotalValue() > 21) {
				(*i)->update(Player::LOST);
				(*i)->clear();
			} else {
				(*i)->wonBettetMoney();
				(*i)->update(Player::WON);
				(*i)->clear();
			}
		}
	} else if (dealerValue == 21) {
		for (auto i = players.begin(); i != players.end(); i++) {
			(*i)->update(Player::LOST);
			(*i)->clear();
		}
	} else {
		for (auto i = players.begin(); i != players.end(); i++) {
			if ((*i)->getCardsTotalValue() > dealerValue && (*i)->getCardsTotalValue() <= 21) {
				(*i)->wonBettetMoney();
				(*i)->update(Player::WON);
				(*i)->clear();
			} else {
				(*i)->update(Player::LOST);
				(*i)->clear();
			}
		}
	}
	dealer->clear();
	phase = BETTING;
	update();
}

std::string Table::getDealerCardsName()
{
	return dealer->getCardsName();
}

int Table::getDealersTotalCardValue()
{
	return dealer->getCardsTotalValue();
}

}
