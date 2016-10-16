/*
 * BlackJackSHAcceptor.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include <App/BlackJackServerServiceHandlerAcceptor.hpp>

namespace App {

BlackJackServerServiceHandlerAcceptor::BlackJackServerServiceHandlerAcceptor(GameLogic::Table* table, const Addr& localAddr, EventHandle::Reactor::Reactor* r) :
		EventHandle::AccConn::Acceptor<BlackJackServerServiceHandler, OSAL::INET::SocketAcceptor>(localAddr, r), table(table)
{

}

BlackJackServerServiceHandler* BlackJackServerServiceHandlerAcceptor::makeServiceHandler()
{
	BlackJackServerServiceHandler* serviceHandler = new BlackJackServerServiceHandler(table, 400);
	return serviceHandler;
}

void BlackJackServerServiceHandlerAcceptor::acceptServiceHandler(BlackJackServerServiceHandler* sh)
{
	acceptor.accept(sh->peer());
}

void BlackJackServerServiceHandlerAcceptor::registerServiceHandler(BlackJackServerServiceHandler* sh)
{
	reactor->registerHandler(sh, EventHandle::Reactor::READ_EVENT);
}

void BlackJackServerServiceHandlerAcceptor::activateServiceHandler(BlackJackServerServiceHandler* sh)
{
	sh->open();
}

handle BlackJackServerServiceHandlerAcceptor::getHandle() const
{
	return acceptor.getHandle();
}

void BlackJackServerServiceHandlerAcceptor::handleEvent(handle h, EventHandle::Reactor::EventType et)
{
	accept();
}

}
