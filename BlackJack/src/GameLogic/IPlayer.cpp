/*
 * IPlayer.cpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */


#include <GameLogic/IPlayer.hpp>

namespace GameLogic {


void IPlayer::giveCard(Card* card)
{
	cards.push_back(card);
}

int IPlayer::getCardsTotalValue()
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

std::string IPlayer::getCardsName()
{
	std::string returnString;
	for(auto i = cards.begin(); i != cards.end(); i++)
	{
		returnString.append((*i)->getCardName());
		if(i != cards.end()-1)
		{
			returnString.append(", ");
		}
	}
	return returnString;
}

void IPlayer::clearCards()
{
	for(auto i = cards.begin(); i != cards.end(); i++)
	{
		delete *i;
	}
	cards.clear();
}


}

