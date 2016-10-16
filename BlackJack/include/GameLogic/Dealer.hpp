/*
 * Dealer.cpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_DEALER_CPP_
#define INCLUDE_GAMELOGIC_DEALER_CPP_

#include <GameLogic/IPlayer.hpp>

namespace GameLogic
{
class Dealer : public IPlayer
{
public:
	/**
	 * @brief - The destructor of the dealer object
	 */
	~Dealer();

	/**
	 * @brief - Returns whether or not the dealer is hitting or standing
	 * @return - true if the dealer is hitting, false if the dealer is standing
	 */
	bool getIsHitting();
};

}



#endif /* INCLUDE_GAMELOGIC_DEALER_CPP_ */
