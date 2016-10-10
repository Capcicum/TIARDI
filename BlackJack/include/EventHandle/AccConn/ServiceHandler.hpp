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

template <class IPC_STREAM>
class ServiceHandler : public Reactor::EventHandler
{
public:
	virtual void open()=0;
	IPC_STREAM& peer();
	std::string remoteAddr();
	void setHandle(handle h);

private:
	IPC_STREAM stream;
};

}
}


#endif /* INCLUDE_EVENTHANDLE_ACCCONN_SERVICEHANDLER_HPP_ */
