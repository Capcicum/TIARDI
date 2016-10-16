/*
 * Dealer.cpp
 *
 *  Created on: 12. okt. 2016
 *      Author: Andersen
 */

#include <GameLogic/Dealer.hpp>

namespace GameLogic
{
Dealer::~Dealer()
{
	clearCards();
}

bool Dealer::getIsHitting()
{
	bool isHitting = true;
	if (getCardsTotalValue() > 16)
	{
		isHitting = false;
	}
	return isHitting;
}

}

