/*
 * ServiceHandler.hpp
 *
 *  Created on: 9. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_EVENTHANDLE_ACCCONN_SERVICEHANDLER_HPP_
#define INCLUDE_EVENTHANDLE_ACCCONN_SERVICEHANDLER_HPP_

#include <EventHandle/Reactor/EventHandler.hpp>
#include <OSAL/INET/SocketStream.hpp>
#include <string>

namespace EventHandle {
namespace AccConn {

template <class IPCSTREAM>
class ServiceHandler : public Reactor::EventHandler
{
public:

	/**
	 * @brief - Virtual function creating an interface for activating the service handler
	 */
	virtual void open()=0;

	/**
	 * @brief - Returns the stream object
	 * @return - The stream object
	 */
	IPCSTREAM& peer()
	{
		return stream;
	}

	/**
	 * NOT IMPLEMENTED
	 */
	std::string remoteAddr()
	{
		return "hej";
	}

	/**
	 * @brief - sets the handle of the stream object
	 * @param h - the handle to set in the stream object
	 */
	void setHandle(handle h)
	{
		stream.setHandle(h);
	}

	/**
	 * @brief - Returns the handle of the stream object
	 * @return - the stream objects handle
	 */
	handle getHandle() const
	{
		return stream.getHandle();
	}

protected:
	IPCSTREAM stream; // The stream obejct used to hold the actual connection
};



}
}


#endif /* INCLUDE_EVENTHANDLE_ACCCONN_SERVICEHANDLER_HPP_ */
