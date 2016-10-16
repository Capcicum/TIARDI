/*
 * BlackJackServerServiceHandlerConnector.hpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_APP_BLACKJACKCLIENTSERVICEHANDLERCONNECTOR_HPP_
#define INCLUDE_APP_BLACKJACKCLIENTSERVICEHANDLERCONNECTOR_HPP_

#include <EventHandle/AccConn/Connector.hpp>
#include <App/BlackJackClientServiceHandler.hpp>
#include <OSAL/INET/SocketConnector.hpp>
#include <EventHandle/Reactor/Reactor.hpp>

namespace App
{

class BlackJackClientServiceHandlerConnector : public EventHandle::AccConn::Connector<BlackJackClientServiceHandler, OSAL::INET::SocketConnector>
{
public:
	BlackJackClientServiceHandlerConnector(EventHandle::Reactor::Reactor* r);
	~BlackJackClientServiceHandlerConnector();
	void connectServiceHandler(BlackJackClientServiceHandler *sh, const Addr &addr);
	void registerServiceHandler(BlackJackClientServiceHandler* sh);
	void activateServiceHandler(BlackJackClientServiceHandler* sh);
};

}

#endif /* INCLUDE_APP_BLACKJACKCLIENTSERVICEHANDLERCONNECTOR_HPP_ */
