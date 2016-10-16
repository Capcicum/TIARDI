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
#include <EventHandle/AccConn/ServiceHandler.hpp>
#include <App/BlackJackServerServiceHandler.hpp>

namespace App {

class BlackJackServerServiceHandlerAcceptor : public EventHandle::AccConn::Acceptor<BlackJackServerServiceHandler, OSAL::INET::SocketAcceptor>
{
public:

	BlackJackServerServiceHandlerAcceptor(GameLogic::Table* table, const Addr& localAddr, EventHandle::Reactor::Reactor* r);

	virtual BlackJackServerServiceHandler* makeServiceHandler();
	virtual void acceptServiceHandler(BlackJackServerServiceHandler* sh);
	virtual void registerServiceHandler(BlackJackServerServiceHandler* sh);
	virtual void activateServiceHandler(BlackJackServerServiceHandler* sh);
	virtual handle getHandle() const;
	virtual void handleEvent(handle h, EventHandle::Reactor::EventType et);

private:
	GameLogic::Table* table;

};

}

#endif /* APP_SERVICEHANDLE_BLACKJACKSHACCEPTOR_HPP_ */
