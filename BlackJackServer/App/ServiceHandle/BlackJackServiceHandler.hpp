/*
 * BlackJackServiceHandler.hpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#ifndef APP_SERVICEHANDLE_BLACKJACKSERVICEHANDLER_HPP_
#define APP_SERVICEHANDLE_BLACKJACKSERVICEHANDLER_HPP_

#include <EventHandle/AccConn/ServiceHandler.hpp>
#include <OSAL/INET/SocketStream.hpp>

namespace App {
namespace ServiceHandle {

class BlackJackServiceHandler : public EventHandle::AccConn::ServiceHandler<OSAL::INET::SocketStream>
{
public:
	BlackJackServiceHandler();
	~BlackJackServiceHandler();
	void open();
	void handleEvent(handle handle, EventHandle::Reactor::EventType et);

};

}}



#endif /* APP_SERVICEHANDLE_BLACKJACKSERVICEHANDLER_HPP_ */
