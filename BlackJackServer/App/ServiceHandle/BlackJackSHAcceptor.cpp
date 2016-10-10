/*
 * BlackJackSHAcceptor.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include "BlackJackSHAcceptor.hpp"

namespace App {
namespace ServiceHandle {

	BlackJackServiceHandler* BlackJackSHAcceptor::makeServiceHandler()
	{
		BlackJackServiceHandler* serviceHandler = new BlackJackServiceHandler();
		return serviceHandler;
	}

	void BlackJackSHAcceptor::acceptServiceHandler(BlackJackServiceHandler* sh)
	{
		OSAL::INET::SocketStream& s = sh->peer();
		acceptor.accept(s);
		//acceptor.accept(sh->peer());
	}

	void BlackJackSHAcceptor::activateServiceHandler(BlackJackServiceHandler* sh)
	{
		reactor->registerHandler(sh, EventHandle::Reactor::READ_EVENT);
		sh->open();
	}

	handle BlackJackSHAcceptor::getHandle() const
	{
		//return acceptor.getHandle();
	}

	void BlackJackSHAcceptor::handleEvent(handle h, EventHandle::Reactor::EventType et)
	{
		//accept();
	}

}}
