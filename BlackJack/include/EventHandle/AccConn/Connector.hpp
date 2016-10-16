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
	//a type definition of the INETAddr
	typedef typename IPCCONNECTOR::PEERADDR Addr;

	/**
	 * @brief - Creates the connector
	 * @param r - A pointer to the associated reactor
	 */
	Connector(Reactor::Reactor* r) : reactor(r) {}

	/**
	 * @brief -  Establishes the connection
	 * @param sh - The service handler to parse the established connection
	 * @param remoteAddr - A data object with information about the port and ip addr to connect to
	 *
	 * Starts connecting the service handler to the remoteAddr,
	 * then registers the service handler with the associated
	 * reactor lastly the service handler is activated.
	 */
	virtual void connect(SERVICEHANDLER *sh, const Addr &remoteAddr)
	{
		connectServiceHandler(sh, remoteAddr);
		registerServiceHandler(sh);
		activateServiceHandler(sh);
	}

	/**
	 * @brief - Used for the async connector
	 */
	virtual void handleEvent(handle handle, Reactor::EventType et)
	{

	}

	/**
	 * @brief - Used for the async connector
	 */
	virtual handle getHandle() const
	{
		return connector.getHandle();
	}

protected:
	/**
	 * @brief - Connects the Service handler
	 * @param sh - A pointer to a service handler to parse the established connection
	 * @param addr - A data object containting the port and IP to connect to
	 *
	 * Will connect to the port and IP and parse the established connection to the provided service handler
	 */
	virtual void connectServiceHandler(SERVICEHANDLER *sh, const Addr &addr) = 0;

	/**
	 * @brief - Will register the service handler in the reactor
	 * @param sh - A pointer to the service handler to register
	 */
	virtual void registerServiceHandler(SERVICEHANDLER* sh) = 0;

	/**
	 * @brief - will activate the service handler
	 * @param sh - a pointer to the service handler to activate
	 */
	virtual void activateServiceHandler(SERVICEHANDLER* sh) = 0;

	Reactor::Reactor* reactor;
	IPCCONNECTOR connector;
};

}
}



#endif /* INCLUDE_EVENTHANDLE_ACCCONN_CONNECTOR_HPP_ */
