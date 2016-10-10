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

namespace EventHandle {
namespace AccConn {

template<class SERVICEHANDLER, class IPCACCEPTOR>
class Acceptor : public Reactor::EventHandler
{
public:
	typedef typename IPCACCEPTOR::PEERADDR Addr;
	Acceptor(const Addr& localAddr, Reactor::Reactor* r);
	virtual void accept();
protected:
	virtual SERVICEHANDLER* makeServiceHandler() = 0;
	virtual void acceptServiceHandler(SERVICEHANDLER* sh) = 0;
	virtual void activateServiceHandler(SERVICEHANDLER* sh) = 0;
	virtual handle getHandle() const;
	virtual void handleEvent(handle h, Reactor::EventType et) = 0;
	IPCACCEPTOR acceptor;
	Reactor::Reactor* reactor;

};

template<class SERVICEHANDLER, class IPCACCEPTOR>
Acceptor<SERVICEHANDLER,IPCACCEPTOR>::Acceptor(const Addr& localAddr, Reactor::Reactor* r) :
	reactor(r)
{
	acceptor.open(localAddr);
	reactor->registerHandler(this, Reactor::ACCEPT_EVENT);
}

template<class SERVICEHANDLER, class IPCACCEPTOR>
void Acceptor<SERVICEHANDLER,IPCACCEPTOR>::accept()
{
	SERVICEHANDLER* serviceHandler = makeServiceHandler();

	acceptServiceHandler(serviceHandler);

	activateServiceHandler(serviceHandler);
}

}
}

#endif /* INCLUDE_EVENTHANDLE_ACCCONN_ACCEPTOR_HPP_ */
