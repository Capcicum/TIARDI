/*
 * Dealer.cpp
 *
 *  Created on: 12. okt. 2016
 *      Author: Andersen
 */

#include <GameLogic/Dealer.hpp>

namespace GameLogic
{
	Dealer::Dealer()
	{

	}
	void Dealer::giveCard(Card* card)
	{
		cards.push_back(card);
	}

	int Dealer::getCardsTotalValue()
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

	bool Dealer::getIsHitting()
	{
		bool isHitting = true;
		if(getCardsTotalValue() > 16)
		{
			isHitting = false;
		}
		return isHitting;
	}

	void Dealer::clear()
	{
		for(auto i = cards.begin(); i != cards.end(); i++)
		{
			delete *i;
		}
		cards.clear();
	}

	std::string Dealer::getCardsName()
	{
		std::string returnString;
		for(auto i = cards.begin(); i != cards.end(); i++)
		{
			returnString.append((*i)->getCardName());
			returnString.append(", ");
		}
		return returnString;
	}

}

