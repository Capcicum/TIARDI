/*
 * Card.cpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#include <GameLogic/Card.hpp>

namespace GameLogic{

Card::Card(Rank r, Suit s) :
		rank(r), suit(s)
{
}

int Card::getValue()
{
	int value = rank;
	if(value > 10)
	{
		value = 10;
	}
	return value;
}

std::string Card::getCardName()
{
	int suitValue = suit;
	int rankValue = rank;

	std::string returnString = rankNames[rankValue-1] + " of " + suitNames[suitValue];

	return returnString;
}

}

