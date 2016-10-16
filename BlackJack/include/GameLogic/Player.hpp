/*
 * Player.hpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_GAMELOGIC_PLAYER_HPP_
#define INCLUDE_GAMELOGIC_PLAYER_HPP_

#include <GameLogic/Card.hpp>
#include <GameLogic/Table.hpp>
#include <GameLogic/IPlayer.hpp>

namespace GameLogic {

class Table;

class Player : public IPlayer
{
public:
	enum ClientUpdates
	{
		DEAL,
		NEWCARD,
		DEALERSECONDCARD,
		DEALERNEWCARD,
		DEALERSTAND,
		WON,
		LOST
	};

	/**
	 * @brief - constructor for the Player class
	 * @param table - reference to Table
	 * @param money - the start money for the
	 */
	Player(Table* table, int money = 200);

	/**
	 * @brief - Destructor for the Player class
	 */
	virtual ~Player();

	/**
	 * @brief - updates the state of the player
	 * @param event - the event to handle
	 */
	virtual void update(ClientUpdates event) = 0;

	/**
	 * @brief - updates the money variable with the bettetmoney variable
	 */
	void wonBettetMoney();

	/**
	 * @brief - clears the player to be ready for new game
	 */
	void clearForNewGame();

	/**
	 * @brief - returns the isReady variable
	 * @return - the isReady
	 */
	bool getIsReady();

	/**
	 * @brief - sets the isReady
	 * @param ready - the value to set the isRedy
	 */
	void setIsReady(bool ready);

	/**
	 * @brief - returns the money variable
	 * @return - the money value
	 */
	int getMoney();

	/**
	 * @brief - sets the money variable
	 * @param value - the value to set the money to
	 */
	void setMoney(int value);

	/**
	 * @brief - gets the bettet money variable
	 * @return - the bettet moeny variable
	 */
	int getBettetMoney();

	/**
	 * @brief - sets the bettetMoney variable
	 * @param value - the value to set the bettetMoney
	 */
	void setBettetMoney(int value);

	/**
	 * @brief - returns the isHitting variable
	 * @return - returns tha value of the isHitting variable
	 */
	bool getIsHitting();

	/**
	 * @brief - sets the isHitting variable
	 * @param hitting - the value to set the isHitting
	 */
	void setIsHitting(bool hitting);

	/**
	 * @brief - returns the table
	 * @return - a pointer to the table
	 */
	Table* getTable();

	/**
	 * @brief - set the table variable
	 * @param t - the pointer to set
	 */
	void setTable(Table* t);

protected:
	/**
	 * @brief - the player bets
	 * @param value - the value to bet
	 */
	void bet(int value);

	/**
	 * @brief - makes the player stand setting the isHitting false
	 */
	void stand();

	/**
	 * @brief - makes the player hit, to get a new card
	 */
	void hit();

private:
	Table* table;
	int money;
	bool isHitting;
	int bettetMoney;
	bool isReady;

};

}

#endif /* INCLUDE_GAMELOGIC_PLAYER_HPP_ */
