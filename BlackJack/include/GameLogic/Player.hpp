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
#include <GameLogic/Table.hpp>

namespace GameLogic {

class Table;

class Player
{
public:
	enum ClientUpdates
	{
		DEAL,
		DEALERFIRSTCARD,
		STARTHITTING,
		NEWCARD,
		DEALERSECONDCARD,
		DEALERNEWCARD,
		DEALERSTAND,
		WON,
		LOST
	};

	Player(Table* table, int money = 200);
	virtual ~Player(){};
	int getMoney();
	void setMoney(int value);
	void wonBettetMoney();
	void bet(int value);
	void giveCard(Card* card);
	std::string getCardsNames();
	int getCardsTotalValue();
	void stand();
	void hit();
	bool getIsHitting();
	void clear();
	void setIsReady(bool ready);
	bool getIsReady();
	virtual void update(ClientUpdates event) = 0;
protected:
	Table* table;
private:
	int money;
	bool isHitting;
	int bettetMoney;
	bool isReady;
	std::vector<Card*> cards;

};

}

#endif /* INCLUDE_GAMELOGIC_PLAYER_HPP_ */
