/*
 * BlackJackServiceHandler.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include "BlackJackServiceHandler.hpp"

namespace App {
namespace ServiceHandle {

BlackJackServiceHandler::BlackJackServiceHandler(GameLogic::Table* table, int money) :
		Player(table, money)
{

}
BlackJackServiceHandler::~BlackJackServiceHandler()
{

}

void BlackJackServiceHandler::open()
{

}

void BlackJackServiceHandler::handleEvent(handle handle, EventHandle::Reactor::EventType et)
{
	std::cout << "from bj handler" << std::endl;
	if(et == EventHandle::Reactor::READ_EVENT)
	{
		std::string msg = "";
		if(stream.receive(msg) == OSAL::INET::SocketStream::SOCKETOK)
		{
			std::cout << msg << std::endl;
			handleEventString(msg);

		}
	}
}

void BlackJackServiceHandler::handleEventString(std::string event)
{
	clientEvents eventType = (clientEvents)atoi(std::string(1, event.at(0)).c_str());

	switch(eventType)
	{
	case BET:
		//int bet = atoi(event.substr(event.size() - 2).c_str());
		break;
	case HIT:
		hit();
		break;
	case STAND:
		stand();
		break;
	case STOP:
		break;
	}

}

void BlackJackServiceHandler::update(GameLogic::Player::ClientUpdates event)
{

}

}}


