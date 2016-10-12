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
#include "TestEventHandler.hpp"
#include "App/ServiceHandle/BlackJackSHAcceptor.hpp"

#include <GameLogic/Table.hpp>

int main()
{

	WSA wsa;
	if(wsa.startUp() == WSA::WSAOK)
	{
		OSAL::INET::SocketStream* socketStream = new OSAL::INET::SocketStream();
		OSAL::INET::INETAddr* addr = new OSAL::INET::INETAddr(27015, inet_addr("127.0.0.1"));
		OSAL::INET::SocketAcceptor* acceptor = new OSAL::INET::SocketAcceptor(*addr);
		OSAL::Demux::Select* sel = new OSAL::Demux::Select();
		OSAL::Demux::Demux* demux = new OSAL::Demux::Demux(sel);
		EventHandle::Reactor::Reactor* reactor = new EventHandle::Reactor::Reactor(demux);

		GameLogic::Table* table = new GameLogic::Table();

		//EventHandle::Reactor::TestEventHandler* eventHandler = new EventHandle::Reactor::TestEventHandler(acceptor);

		App::ServiceHandle::BlackJackServiceHandler* serviceHandler = new App::ServiceHandle::BlackJackServiceHandler(table, 400);
		std::cout << "Initialised" << std::endl;

		std::cout << "accepting" << std::endl;
		if(acceptor->accept(serviceHandler->peer()) == OSAL::INET::SocketAcceptor::SOCKACCOK)
		{
			std::cout << "accepted" << std::endl;
		}
		else
		{
			printf("createSocket failed with error: %d\n", WSAGetLastError());
			std::cout << "error" << std::endl;
		}

		reactor->registerHandler(serviceHandler, EventHandle::Reactor::READ_EVENT);

		table->addNewPlayer(serviceHandler);

		/*App::ServiceHandle::BlackJackSHAcceptor* shAcceptor = new App::ServiceHandle::BlackJackSHAcceptor(*addr, reactor);

		reactor->registerHandler(shAcceptor, EventHandle::Reactor::ACCEPT_EVENT);*/

		while(true)
		{
			reactor->handleEvents(NULL);
		}

	}
	return 0;
}


