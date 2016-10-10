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
	virtual void open()=0;

	IPCSTREAM& peer()
	{
		return stream;
	}

	std::string remoteAddr()
	{
		return "hej";
	}

	void setHandle(handle h)
	{
		stream.setHandle(h);
	}

	handle getHandle() const
	{
		return stream.getHandle();
	}

protected:
	IPCSTREAM stream;
};



}
}


#endif /* INCLUDE_EVENTHANDLE_ACCCONN_SERVICEHANDLER_HPP_ */
