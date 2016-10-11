/*
 * GameLogic.cpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */

#include <GameLogic/GameLogic.hpp>
#include <string>
#include <sstream>

namespace GameLogic {

/*GameLogic::GameLogic() {
	// TODO Auto-generated constructor stub

}

GameLogic::~GameLogic() {
	// TODO Auto-generated destructor stub
}


int GameLogic::addPlayer(Player player) {
	players.push_back(player);
	return players.size() - 1;
}

std::string GameLogic::startGame(int id) {
	Player player = players[id];
	player.giveCard(drawCard());
	player.giveCard(drawCard());
	checkForAce(id);
	return "Welcome. Your cards are: " + player.getCards() + " \n giving a total of: " + intToString(player.getCardTotal());
}

void GameLogic::checkForAce(int id) {
	if (players[id].getCardTotal() <= 21) {
		return;
	} else {
		players[id].makeAcesOnes();
	}
}

std::string GameLogic::hit(int id) {
	Player player = players[id];
	player.giveCard(drawCard());
	checkForAce(id);
	return "You got another card. Your cards are: " + player.getCards() + " \n giving a total of: " + intToString(player.getCardTotal());
}

std::string GameLogic::stick(int id) {
	Player player = players[id];
	player.stick();
	return "You decided to stick. Your cards are: " + player.getCards() + " \n giving a total of: " + intToString(player.getCardTotal());
}

std::string GameLogic::intToString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

int GameLogic::drawCard() {
	srand(time(NULL));
	return rand() % 11 + 1;
}*/

}


