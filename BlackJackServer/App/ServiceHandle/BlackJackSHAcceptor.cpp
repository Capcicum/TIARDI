/*
 * BlackJackSHAcceptor.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include "BlackJackSHAcceptor.hpp"

namespace App {
namespace ServiceHandle {

	BlackJackSHAcceptor::BlackJackSHAcceptor(const Addr& localAddr, EventHandle::Reactor::Reactor* r) :
			EventHandle::AccConn::Acceptor<BlackJackServiceHandler, OSAL::INET::SocketAcceptor>(localAddr, r)
	{
	}

	BlackJackServiceHandler* BlackJackSHAcceptor::makeServiceHandler()
	{
		std::cout << "makeServiceHandler" << std::endl;
		//BlackJackServiceHandler* serviceHandler = new BlackJackServiceHandler();
		//return serviceHandler;
	}

	void BlackJackSHAcceptor::acceptServiceHandler(BlackJackServiceHandler* sh)
	{
		std::cout << "acceptServiceHandler" << std::endl;
		acceptor.accept(sh->peer());
	}

	void BlackJackSHAcceptor::activateServiceHandler(BlackJackServiceHandler* sh)
	{
		std::cout << "activateServiceHandler" << std::endl;
		reactor->registerHandler(sh, EventHandle::Reactor::READ_EVENT);
		sh->open();
	}

	handle BlackJackSHAcceptor::getHandle() const
	{
		std::cout << "acceptor getHandle" << std::endl;
		return acceptor.getHandle();
	}

	void BlackJackSHAcceptor::handleEvent(handle h, EventHandle::Reactor::EventType et)
	{
		std::cout << "acceptor handleEvent" << std::endl;
		accept();
	}

}}
