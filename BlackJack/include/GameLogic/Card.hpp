/*
 * Card.hpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_CARD_HPP_
#define INCLUDE_GAMELOGIC_CARD_HPP_

namespace GameLogic {

class Card
{
public:
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

	Card(Rank r, Suit s);
	int getValue();
private:
	Rank rank;
	Suit suit;
};

}



#endif /* INCLUDE_GAMELOGIC_CARD_HPP_ */
