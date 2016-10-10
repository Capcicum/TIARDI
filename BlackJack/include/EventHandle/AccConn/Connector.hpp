/*
 * Connector.hpp
 *
 *  Created on: 9. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_EVENTHANDLE_ACCCONN_CONNECTOR_HPP_
#define INCLUDE_EVENTHANDLE_ACCCONN_CONNECTOR_HPP_

#include <EventHandle/Reactor/EventHandler.hpp>
#include <EventHandle/Reactor/Reactor.hpp>

namespace EventHandle {
namespace AccConn {

template<class SERVICEHANDLER, class IPCCONNECTOR>
class Connector : public Reactor::EventHandler
{
public:
	typedef typename IPCCONNECTOR::PEERADDR Addr;
	Connector(Reactor::Reactor* r);
	virtual void connect(SERVICEHANDLER *sh, const Addr &remoteAddr);
protected:
	virtual void connectServiceHandler(SERVICEHANDLER *sh, const Addr &addr);
	virtual void registerServiceHandler(SERVICEHANDLER* sh);
	virtual void activateServiceHandler(SERVICEHANDLER* sh);
	virtual void complete(handle h);
	virtual void handleEvent(handle h, Reactor::EventType et);
private:
	IPCCONNECTOR acceptor;
};

}
}



#endif /* INCLUDE_EVENTHANDLE_ACCCONN_CONNECTOR_HPP_ */
