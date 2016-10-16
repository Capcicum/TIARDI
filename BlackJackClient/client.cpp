/*
 * client.cpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */

#include <App/BlackJackClientServiceHandlerConnector.hpp>
#include "OSAL/Win32/INET/WSA.hpp"
#include <EventHandle/Reactor/ReactorFactory.hpp>

int main()
{
	WSA wsa;
	if(wsa.startUp() == WSA::WSAOK)
	{
		EventHandle::Reactor::ReactorFactory* factory = new EventHandle::Reactor::ReactorFactory(EventHandle::Reactor::ReactorFactory::SELECT);

		App::BlackJackClientServiceHandlerConnector* connector = new App::BlackJackClientServiceHandlerConnector(factory->instance());

		App::BlackJackClientServiceHandler* serviceHandler = new App::BlackJackClientServiceHandler();

		connector->connect(serviceHandler, OSAL::INET::INETAddr(8888, inet_addr("127.0.0.1")));

		while(true)
		{
			factory->instance()->handleEvents();
		}
	}
	return 0;
}
