/*
 * Dealer.cpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_DEALER_CPP_
#define INCLUDE_GAMELOGIC_DEALER_CPP_

#include <GameLogic/Deck.hpp>
#include <GameLogic/Player.hpp>

namespace GameLogic
{
class Dealer
{
public:
	Dealer();
	void giveCard(Card* card);
	int getCardsTotalValue();
	bool getIsHitting();
	void clear();
	std::string getCardsName();
private:
	std::vector<Card*> cards;
};

}



#endif /* INCLUDE_GAMELOGIC_DEALER_CPP_ */
