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

	/**
	 * @brief - constructor
	 * @param numOfDeck - the number of decks to use
	 */
	Table(int numOfDecks = 1);

	/**
	 * @brief - the destructor
	 */
	~Table();

	/**
	 * @brief - adds a new player to the game
	 * @param player -  pointer to the player to be added
	 */
	void addNewPlayer(Player* player);

	/**
	 * @brief - deletes a player from the game
	 * @param player - a pointer to the player to be deleted
	 */
	void deletePlayer(Player* player);

	/**
	 * @brief - starts a new game
	 */
	void startNewGame();

	/**
	 * @brief - updates the game, usually called by the players to update the game
	 */
	void update();

	/**
	 * @brief - gets the names of the card of the dealer
	 * @return - a string with card names
	 */
	std::string getDealerCardsName();

	/**
	 * @brief - get the total value of the dealers cards
	 * @return - the value of the dealers cards.
	 */
	int getDealersTotalCardValue();

private:
	void dealNewRound();

	void betting();
	void dealing();
	void housePlaying();
	void exit();

	GamePhases phase;
	int numOfDecks;
	Deck* deck;
	Dealer* dealer;
	std::vector<Player*> players;
};
}



#endif /* INCLUDE_GAMELOGIC_TABLE_HPP_ */
