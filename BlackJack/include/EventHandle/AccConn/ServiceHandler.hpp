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
	IPCSTREAM& peer();
	std::string remoteAddr();
	void setHandle(handle h);
	virtual handle getHandle() const;

protected:
	IPCSTREAM stream;
};


template <class IPCSTREAM>
IPCSTREAM& ServiceHandler<IPCSTREAM>::peer()
{
	return stream;
}

template <class IPCSTREAM>
std::string ServiceHandler<IPCSTREAM>::remoteAddr()
{
	return "hej";
}

template <class IPCSTREAM>
void ServiceHandler<IPCSTREAM>::setHandle(handle h)
{
	stream.setHandle(h);
}

template <class IPCSTREAM>
handle ServiceHandler<IPCSTREAM>::getHandle() const
{
	return stream.getHandle();
}

}
}


#endif /* INCLUDE_EVENTHANDLE_ACCCONN_SERVICEHANDLER_HPP_ */
