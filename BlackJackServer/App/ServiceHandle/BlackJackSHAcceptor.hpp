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

	typedef typename OSAL::INET::SocketAcceptor::PEERADDR Addr;

	BlackJackSHAcceptor(const Addr& localAddr, EventHandle::Reactor::Reactor* r);

	BlackJackServiceHandler* makeServiceHandler();

	void acceptServiceHandler(BlackJackServiceHandler* sh);

	void activateServiceHandler(BlackJackServiceHandler* sh);

	handle getHandle() const;

	void handleEvent(handle h, EventHandle::Reactor::EventType et);
private:

};

}
}

#endif /* APP_SERVICEHANDLE_BLACKJACKSHACCEPTOR_HPP_ */
