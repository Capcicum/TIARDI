/*
 * Acceptor.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include <EventHandle/AccConn/Acceptor.hpp>

namespace EventHandle {
namespace AccConn {

template<class SERVICEHANDLER, class IPCACCEPTOR>
Acceptor<SERVICEHANDLER,IPCACCEPTOR>::Acceptor(const Addr& localAddr, Reactor::Reactor* r)
{
	acceptor.open(localAddr);
	r->registerHandler(this, Reactor::ACCEPT_EVENT);
}

template<class SERVICEHANDLER, class IPCACCEPTOR>
void Acceptor<SERVICEHANDLER,IPCACCEPTOR>::accept()
{
	SERVICEHANDLER* serviceHandler = makeServiceHandler();

	acceptServiceHandler(serviceHandler);

	activateServiceHandler(serviceHandler);
}


}}
