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

	/**
	 *@brief - The Constructor for the deck object
	 *@param numOfDecks - the numbers of 52 cards to add to the deck
	 */
	Deck(int numOfDecks = 1);

	/**
	 * @brief - The Deck destructor
	 */
	~Deck();

	/**
	 * @brief - Clears the and deletes the card objects in the vector
	 */
	void clear();

	/**
	 * @brief - Creates and fills the vector with Card objects
	 * @param - the number of 52 instances of the Card object to put in the vector
	 */
	void createNewDeck(int numOfDecks);

	/**
	 * @brief - shuffles the deck vector
	 */
	void shuffleDeck();

	/**
	 * @brief - return the back most card from the vector and deletes it from the vector.
	 * @return - the back most card from the vector.
	 */
	Card* getCard();

	/**
	 * @brief - returns the number of cards left in the card vector
	 * @return - the number of cards left in the vector
	 */
	int getCardsLeft();

private:
	std::vector<Card*> deck;
};

}

#endif /* INCLUDE_GAMELOGIC_DECK_HPP_ */
