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

}

