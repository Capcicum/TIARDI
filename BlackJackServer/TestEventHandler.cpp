/*
 * TestEventHandler.cpp
 *
 *  Created on: 9. okt. 2016
 *      Author: Andersen
 */

#include "TestEventHandler.hpp"


namespace EventHandle {
namespace Reactor {

TestEventHandler::TestEventHandler(OSAL::INET::SocketStream* stream) :
		stream(stream)
{

}

void TestEventHandler::handleEvent(handle handle, EventType et)
{
	if(et == READ_EVENT)
	{
		std::string msg = "";
		if(stream->receive(msg) == OSAL::INET::SocketStream::SOCKETOK)
		{
			std::cout << msg << std::endl;
		}
	}
}

handle TestEventHandler::getHandle() const
{
	return stream->getSocket();
}

}}



