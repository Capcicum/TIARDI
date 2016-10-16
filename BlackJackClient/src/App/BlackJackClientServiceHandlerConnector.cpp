/*
 * BlackJackClientServiceHandlerConnector.cpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#include <App/BlackJackClientServiceHandlerConnector.hpp>

namespace App
{


BlackJackClientServiceHandlerConnector::BlackJackClientServiceHandlerConnector(EventHandle::Reactor::Reactor* r) :
		EventHandle::AccConn::Connector<BlackJackClientServiceHandler, OSAL::INET::SocketConnector>(r)
{

}

BlackJackClientServiceHandlerConnector::~BlackJackClientServiceHandlerConnector()
{

}

void BlackJackClientServiceHandlerConnector::connectServiceHandler(BlackJackClientServiceHandler *sh, const Addr &addr)
{
	connector.connect(addr, sh->peer());
}


void BlackJackClientServiceHandlerConnector::registerServiceHandler(BlackJackClientServiceHandler* sh)
{
	reactor->registerHandler(sh, EventHandle::Reactor::READ_EVENT);
}

void BlackJackClientServiceHandlerConnector::activateServiceHandler(BlackJackClientServiceHandler* sh)
{
	sh->open();
}

}

