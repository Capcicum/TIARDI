/*
 * BlackJackServiceHandler.hpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#ifndef APP_SERVICEHANDLE_BLACKJACKSERVICEHANDLER_HPP_
#define APP_SERVICEHANDLE_BLACKJACKSERVICEHANDLER_HPP_

#include <EventHandle/AccConn/ServiceHandler.hpp>
#include <OSAL/INET/SocketStream.hpp>
#include <GameLogic/Player.hpp>

namespace App {

class BlackJackServerServiceHandler : public EventHandle::AccConn::ServiceHandler<OSAL::INET::SocketStream>, public GameLogic::Player
{
public:
	enum clientEvents
	{
		BET,
		HIT,
		STAND,
		STOP
	};

	BlackJackServerServiceHandler(GameLogic::Table* table, int money);
	~BlackJackServerServiceHandler();
	void open();
	void handleEvent(handle handle, EventHandle::Reactor::EventType et);
	void update(GameLogic::Player::ClientUpdates event);

private:
	void handleEventString(std::string event);

};

}



#endif /* APP_SERVICEHANDLE_BLACKJACKSERVICEHANDLER_HPP_ */
