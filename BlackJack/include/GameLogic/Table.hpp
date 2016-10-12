/*
 * Table.hpp
 *
 *  Created on: 12. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_TABLE_HPP_
#define INCLUDE_GAMELOGIC_TABLE_HPP_

#include <GameLogic/Player.hpp>
#include <GameLogic/Dealer.hpp>
#include <GameLogic/Deck.hpp>
#include <algorithm>


namespace GameLogic {

class Player;
class Dealer;

class Table
{
public:
	enum GamePhases {
		BETTING,
		DEALING,
		HOUSEPLAYING,
		EXIT
	};

	Table();
	void addNewPlayer(Player* player);
	void deletePlayer(Player* player);
	void startNewGame();
	void dealNewRound();
	void update();
	void betting();
	void dealing();
	void housePlaying();
	void exit();
	std::string getDealerCardsName();
	int getDealersTotalCardValue();

private:
	GamePhases phase;
	Deck* deck;
	Dealer* dealer;
	std::vector<Player*> players;
};
}



#endif /* INCLUDE_GAMELOGIC_TABLE_HPP_ */
