/*
 * BlackJackServiceHandler.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include "BlackJackServiceHandler.hpp"

namespace App {
namespace ServiceHandle {

BlackJackServiceHandler::BlackJackServiceHandler()
{
	std::cout << "BJServiceHandler constructor" << std::endl;
}
BlackJackServiceHandler::~BlackJackServiceHandler()
{
	std::cout << "BJServiceHandler destructor" << std::endl;
}

void BlackJackServiceHandler::open()
{
	std::cout << "BJServiceHandler open" << std::endl;
}

void BlackJackServiceHandler::handleEvent(handle handle, EventHandle::Reactor::EventType et)
{
	std::cout << "from bj handler" << std::endl;
	if(et == EventHandle::Reactor::READ_EVENT)
	{
		std::cout << "it is a read event" << std::endl;
		std::string msg = "";
		if(stream.receive(msg) == OSAL::INET::SocketStream::SOCKETOK)
		{
			std::cout << "receive ok" << std::endl;
			std::cout << msg << std::endl;
		}
	}
}

}}


