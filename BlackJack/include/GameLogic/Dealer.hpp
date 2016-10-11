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
	void startGame();
	void addNewPlayer();
	void giveCard();
	void deal();

private:
	Deck* deck;
	std::vector<Player*> players;
};

}



#endif /* INCLUDE_GAMELOGIC_DEALER_CPP_ */
