/*
 * BlackJackPlayer.hpp
 *
 *  Created on: 12. okt. 2016
 *      Author: Andersen
 */

#ifndef APP_BLACKJACKPLAYER_HPP_
#define APP_BLACKJACKPLAYER_HPP_

#include <OSAL/INET/SocketStream.hpp>
#include <EventHandle/AccConn/ServiceHandler.hpp>
#include <GameLogic/Player.hpp>
#include <limits>
#include <iostream>
#include <sstream>

namespace App
{

class BlackJackClientServiceHandler : public EventHandle::AccConn::ServiceHandler<OSAL::INET::SocketStream>
{
public:
	enum clientEvents
	{
		BET,
		HIT,
		STAND,
		STOP
	};

	BlackJackClientServiceHandler();
	~BlackJackClientServiceHandler();
	void open();
	void handleEvent(handle handle, EventHandle::Reactor::EventType et);
	void handleEventString(std::string event);

private:
	void deal(std::string event);
	void dealerNewCard(std::string event);
	void dealerSecondCard(std::string event);
	void dealerStand(std::string event);
	void lost(std::string event);
	void newCard(std::string event);
	void won(std::string event);

	void betting();
	void sendBet(int money);
	void sendIsHitting(clientEvents event);
};

}





#endif /* APP_BLACKJACKPLAYER_HPP_ */
