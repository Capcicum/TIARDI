/*
 * IPlayer.hpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_IPLAYER_HPP_
#define INCLUDE_GAMELOGIC_IPLAYER_HPP_

#include <GameLogic/Card.hpp>
#include <vector>

namespace GameLogic {

class IPlayer
{
public:

	virtual ~IPlayer(){}

	/**
	 *@brief - Gives card to the IPlayer
	 *@param card - the card to give
	 */
	void giveCard(Card* card);

	/**
	 *@brief - gets the total value of the cards located in the cards vector
	 *@return - returns the total value of the cards
	 */
	int getCardsTotalValue();

	/**
	 *@brief - return a string with all the names of the cards in the vector
	 *@return - a string with the names
	 */
	std::string getCardsName();

	/**
	 *@brief - clears the vector cards and deletes the card object
	 */
	void clearCards();

	/**
	 *@brief - virtual function to fid out if IPlayer is hitting or not
	 *@return - return true if hitting and false if stadning
	 */
	virtual bool getIsHitting() = 0;
private:
	std::vector<Card*> cards;
};

}



#endif /* INCLUDE_GAMELOGIC_IPLAYER_HPP_ */
