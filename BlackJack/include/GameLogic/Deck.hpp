/*
 * Deck.hpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_DECK_HPP_
#define INCLUDE_GAMELOGIC_DECK_HPP_

#include <vector>
#include <algorithm>
#include <GameLogic/Card.hpp>

namespace GameLogic {

class Deck {
public:
	Deck(int numOfDecks);
	void clear();
	void createNewDeck(int numOfDecks);
	void shuffleDeck();
	Card* getCard();
	int getCardsLeft();
private:
	std::vector<Card*> deck;
};

}



#endif /* INCLUDE_GAMELOGIC_DECK_HPP_ */
