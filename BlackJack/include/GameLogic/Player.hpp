/*
 * Player.hpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_PLAYER_HPP_
#define INCLUDE_GAMELOGIC_PLAYER_HPP_

#include <string>
#include <vector>
#include <GameLogic/Card.hpp>

namespace GameLogic {

class Player
{
public:
	Player();
	Player(int money);
	int getMoney();
	void setMoney(int value);
	void bet(int value);
	void getCard();
	int getCardsTotalValue();
	//void giveCard(Card* card);
	//std::string getCards();
	void stick();
	bool getHitStick();
private:
	int money;
	std::vector<Card*> cards;
	bool stickFlag;
};

}

#endif /* INCLUDE_GAMELOGIC_PLAYER_HPP_ */
