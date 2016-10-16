/*
 * Card.hpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_CARD_HPP_
#define INCLUDE_GAMELOGIC_CARD_HPP_

#include <string>

namespace GameLogic {

class Card
{
public:
	const std::string rankNames[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	const std::string suitNames[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

	enum Rank
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING
	};
	enum Suit
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};

	/**
	 * @brief - The constructor of the Card class
	 * @param r - The Rank of the card
	 * @param s - The Suit of the card
	 */
	Card(Rank r, Suit s);

	/**
	 * @brief - Returns the value of the Card
	 * @return - the value of the object
	 */
	int getValue();

	/**
	 * @brief - return the full name of the card object
	 * @return - the card name based on the rank and suit
	 */
	std::string getCardName();
private:
	Rank rank;
	Suit suit;
};

}



#endif /* INCLUDE_GAMELOGIC_CARD_HPP_ */
