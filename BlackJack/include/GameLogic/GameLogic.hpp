/*
 * GameLogic.hpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_GAMELOGIC_HPP_
#define INCLUDE_GAMELOGIC_GAMELOGIC_HPP_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <GameLogic/Player.hpp>

namespace GameLogic {

class GameLogic : Player {
public:
	GameLogic();
	~GameLogic();
	int addPlayer(Player* player);
	std::string startGame(int id);
	void checkForAce(int id);
	std::string hit(int id);
	std::string stick (int id);
	int drawCard();
	std::string intToString(int value);
private:
	std::vector<int> dealerCards;
	std::vector<Player> players;

};

}

#endif /* INCLUDE_GAMELOGIC_GAMELOGIC_HPP_ */
