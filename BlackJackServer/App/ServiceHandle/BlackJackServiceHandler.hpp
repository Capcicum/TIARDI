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
#include <string>
#include <sstream>

namespace App {
namespace ServiceHandle {

class BlackJackServiceHandler : public EventHandle::AccConn::ServiceHandler<OSAL::INET::SocketStream>, GameLogic::Player
{
public:
	enum clientEvents
	{
		BET,
		HIT,
		STAND,
		STOP
	};

	BlackJackServiceHandler(GameLogic::Table* table, int money);
	~BlackJackServiceHandler();
	void open();
	void handleEvent(handle handle, EventHandle::Reactor::EventType et);
	void handleEventString(std::string event);
	void update(GameLogic::Player::ClientUpdates event);
	std::string intToString(int value);

};

}}



#endif /* APP_SERVICEHANDLE_BLACKJACKSERVICEHANDLER_HPP_ */
