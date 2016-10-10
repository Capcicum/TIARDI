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
	virtual SERVICEHANDLER* makeServiceHandler();
	virtual void acceptServiceHandler(SERVICEHANDLER* sh);
	virtual void activateServiceHandler(SERVICEHANDLER* sh);
	virtual handle getHandle() const;
	virtual void handleEvent(handle h, Reactor::EventType et);
private:
	IPCACCEPTOR acceptor;
};

}
}

#endif /* INCLUDE_EVENTHANDLE_ACCCONN_ACCEPTOR_HPP_ */
