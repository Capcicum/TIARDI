/*
 * Table.cpp
 *
 *  Created on: 12. okt. 2016
 *      Author: Andersen
 */

#include <GameLogic/Table.hpp>
#include <iostream>

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
			}
		}
		for(auto i = players.begin(); i != players.end(); i++)
		{
			if((*i)->getIsHitting())
			{
				return;
			}
		}
		for(auto i = players.begin(); i != players.end(); i++)
		{
			if((*i)->getIsHitting())
			{
				(*i)->setIsReady(false);
			}
		}
		phase = HOUSEPLAYING;
		update();

	}

	void Table::housePlaying()
	{
		dealer->giveCard(deck->getCard());
		for(auto i = players.begin(); i != players.end(); i++)
		{
			(*i)->update(Player::DEALERSECONDCARD);
		}
		while(dealer->getIsHitting())
		{
			dealer->giveCard(deck->getCard());
			for(auto i = players.begin(); i != players.end(); i++)
			{
				(*i)->update(Player::DEALERNEWCARD);
			}
		}
		phase = EXIT;
	}

void Table::exit() {
	int dealerValue = dealer->getCardsTotalValue();
	if (dealerValue > 21) {
		for (auto i = players.begin(); i != players.end(); i++) {
			if ((*i)->getCardsTotalValue() > 21) {
				(*i)->clear();
			} else {
				(*i)->wonBettetMoney();
				(*i)->clear();
			}
		}
	} else if (dealerValue == 21) {
		for (auto i = players.begin(); i != players.end(); i++) {
			(*i)->clear();
		}
	} else {
		for (auto i = players.begin(); i != players.end(); i++) {
			if ((*i)->getCardsTotalValue() > dealerValue) {
				(*i)->wonBettetMoney();
				(*i)->clear();
			} else {
				(*i)->clear();
			}
		}
	}
	phase = BETTING;
}

std::string Table::getDealerCardsName()
{
	return dealer->getCardsName();
}

}
