/*
 * Acceptor.hpp
 *
 *  Created on: 9. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_EVENTHANDLE_ACCCONN_ACCEPTOR_HPP_
#define INCLUDE_EVENTHANDLE_ACCCONN_ACCEPTOR_HPP_

#include <EventHandle/Reactor/EventHandler.hpp>
#include <EventHandle/Reactor/Reactor.hpp>
#include <OSAL/INET/INETAddr.hpp>
#include <OSAL/INET/SocketAcceptor.hpp>

namespace EventHandle {
namespace AccConn {

template<class SERVICEHANDLER, class IPCACCEPTOR>
class Acceptor : public Reactor::EventHandler
{
public:
	typedef typename IPCACCEPTOR::PEERADDR Addr;

	Acceptor(const Addr& localAddr, Reactor::Reactor* r) :
		reactor(r)
	{
		std::cout << "from acceptor" << std::endl;
		acceptor.open(localAddr);
	}

	virtual void accept()
	{
		std::cout << "accept connection" << std::endl;
		SERVICEHANDLER* serviceHandler = makeServiceHandler();

		acceptServiceHandler(serviceHandler);

		activateServiceHandler(serviceHandler);
	}

protected:
	virtual SERVICEHANDLER* makeServiceHandler() = 0;
	virtual void acceptServiceHandler(SERVICEHANDLER* sh) = 0;
	virtual void activateServiceHandler(SERVICEHANDLER* sh) = 0;
	virtual void handleEvent(handle h, Reactor::EventType et) = 0;

	IPCACCEPTOR acceptor;
	Reactor::Reactor* reactor;

};

}
}

#endif /* INCLUDE_EVENTHANDLE_ACCCONN_ACCEPTOR_HPP_ */
