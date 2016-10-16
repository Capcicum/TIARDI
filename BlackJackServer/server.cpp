/*
 * server.cpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */


#include <OSAL/INET/SocketConnector.hpp>
#include <OSAL/INET/SocketAcceptor.hpp>
#include <OSAL/INET/SocketStream.hpp>
#include <OSAL/INET/INETAddr.hpp>
#include <OSAL/Demux/Select.hpp>
#include <EventHandle/Reactor/Reactor.hpp>
#include <DataType.hpp>
#include "OSAL/Win32/INET/WSA.hpp"
#include <iostream>
#include <string>

#include <App/BlackJackServerServiceHandlerAcceptor.hpp>
#include <EventHandle/Reactor/ReactorFactory.hpp>

#include <GameLogic/Table.hpp>

int main()
{

	WSA wsa;
	if(wsa.startUp() == WSA::WSAOK)
	{
		EventHandle::Reactor::ReactorFactory* factory = new EventHandle::Reactor::ReactorFactory(EventHandle::Reactor::ReactorFactory::SELECT);

		GameLogic::Table* table = new GameLogic::Table();

		App::BlackJackServerServiceHandlerAcceptor* shAcceptor = new App::BlackJackServerServiceHandlerAcceptor(table, OSAL::INET::INETAddr(8888, INADDR_ANY), factory->instance());

		shAcceptor->registerAcceptor();

		while(true)
		{
			factory->instance()->handleEvents();
		}

	}
	return 0;
}


