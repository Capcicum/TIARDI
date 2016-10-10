/*
 * BlackJackSHAcceptor.hpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#ifndef APP_SERVICEHANDLE_BLACKJACKSHACCEPTOR_HPP_
#define APP_SERVICEHANDLE_BLACKJACKSHACCEPTOR_HPP_

#include <EventHandle/AccConn/Acceptor.hpp>
#include <OSAL/INET/SocketAcceptor.hpp>
#include "BlackJackServiceHandler.hpp"
#include <EventHandle/AccConn/ServiceHandler.hpp>

namespace App {
namespace ServiceHandle {

class BlackJackSHAcceptor : public EventHandle::AccConn::Acceptor<BlackJackServiceHandler, OSAL::INET::SocketAcceptor>
{
public:
	using EventHandle::AccConn::Acceptor<BlackJackServiceHandler, OSAL::INET::SocketAcceptor>::Acceptor;

	BlackJackServiceHandler* makeServiceHandler()
	{
		BlackJackServiceHandler* serviceHandler = new BlackJackServiceHandler();
		return serviceHandler;
	}

	void acceptServiceHandler(BlackJackServiceHandler* sh)
	{
		acceptor.accept(sh->peer());
	}

	void activateServiceHandler(BlackJackServiceHandler* sh)
	{
		reactor->registerHandler(sh, EventHandle::Reactor::READ_EVENT);
		sh->open();
	}

	handle getHandle() const
	{
		return acceptor.getHandle();
	}

	void handleEvent(handle h, EventHandle::Reactor::EventType et)
	{
		accept();
	}

private:

};

}
}

#endif /* APP_SERVICEHANDLE_BLACKJACKSHACCEPTOR_HPP_ */
