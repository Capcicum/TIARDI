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
	//typedef for the INETAddr
	typedef typename IPCACCEPTOR::PEERADDR Addr;

	/**
	 * @brief -  Creates the acceptor class
	 * @param - localAddr The data object containing the address and port to listen for
	 * @param - r The reactor instance for which the acceptor shall register
	 *
	 * Creates the acceptor and calls the open function to start listen for connection
	 */
	Acceptor(const Addr& localAddr, Reactor::Reactor* r) :
		reactor(r)
	{
		acceptor.open(localAddr);
	}

	/**
	 * @brief -  Accept a connection and creates a servicehandler
	 *
	 * Starts creating a servicehandler, then accepts the connection
	 * then registers the servicehandler and activates it
	 */
	virtual void accept()
	{
		SERVICEHANDLER* serviceHandler = makeServiceHandler();

		acceptServiceHandler(serviceHandler);

		registerServiceHandler(serviceHandler);

		activateServiceHandler(serviceHandler);
	}

	/**
	 * @brief -  Registers the acceptor with the associated reactor
	 */
	virtual void registerAcceptor()
	{
		reactor->registerHandler(this, Reactor::ACCEPT_EVENT);
	}

protected:
	/**
	 * @breif -  Creates the associated Service Handler
	 * @return -  a pointer to the created servicehandler
	 */
	virtual SERVICEHANDLER* makeServiceHandler() = 0;

	/**
	 * @brief - Accepts a connection and parses it to the service handler
	 * @param sh - The service handler to parse the established connection
	 */
	virtual void acceptServiceHandler(SERVICEHANDLER* sh) = 0;

	/**
	 * @brief - Registers the service handler with the reactor
	 * @param sh - a pointer to the service handler to register
	 */
	virtual void registerServiceHandler(SERVICEHANDLER* sh) = 0;

	/**
	 * @breif - Activates the service handler
	 * @param sh - A pointer to the service handler to activate
	 */
	virtual void activateServiceHandler(SERVICEHANDLER* sh) = 0;

	/**
	 * @breif -  Handles the income event
	 * @param h - The handle that is READY
	 * @param et -  The type of event for which the handle is READY
	 */
	virtual void handleEvent(handle h, Reactor::EventType et) = 0;

	IPCACCEPTOR acceptor;
	Reactor::Reactor* reactor;

};

}
}

#endif /* INCLUDE_EVENTHANDLE_ACCCONN_ACCEPTOR_HPP_ */
