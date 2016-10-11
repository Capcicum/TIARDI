/*
 * TestEventHandler.hpp
 *
 *  Created on: 9. okt. 2016
 *      Author: Andersen
 */

#ifndef TESTEVENTHANDLER_HPP_
#define TESTEVENTHANDLER_HPP_

#include <EventHandle/Reactor/EventHandler.hpp>
#include <OSAL/INET/SocketStream.hpp>
#include <DataType.hpp>
#include <OSAL/INET/SocketAcceptor.hpp>

namespace EventHandle {
namespace Reactor {

class TestEventHandler : public EventHandle::Reactor::EventHandler
{
public:
	TestEventHandler(OSAL::INET::SocketAcceptor* stream);

	void handleEvent(handle handle, EventType et);

	handle getHandle() const;

private:
	OSAL::INET::SocketAcceptor* stream;
};

}}

#endif /* TESTEVENTHANDLER_HPP_ */
