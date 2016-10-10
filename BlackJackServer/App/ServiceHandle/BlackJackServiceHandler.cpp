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

}
BlackJackServiceHandler::~BlackJackServiceHandler()
{

}

void BlackJackServiceHandler::open()
{

}

void BlackJackServiceHandler::handleEvent(handle handle, EventHandle::Reactor::EventType et)
{
	if(et == EventHandle::Reactor::READ_EVENT)
	{
		std::string msg = "";
		if(stream.receive(msg) == OSAL::INET::SocketStream::SOCKETOK)
		{
			std::cout << msg << std::endl;
		}
	}
}

}}


