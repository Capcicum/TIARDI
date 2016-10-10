/*
 * Event_Handler.hpp
 *
 *  Created on: 14. sep. 2016
 *      Author: Andersen
 */

#ifndef EVENT_HANDLER_HPP_
#define EVENT_HANDLER_HPP_

#include <DataType.hpp>
#include <EventHandle/Reactor/EventType.hpp>

namespace EventHandle {
namespace Reactor {

class EventHandler
{
public:
	virtual void handleEvent(handle handle, EventType et) = 0;

	virtual handle getHandle() const = 0;

protected:
	virtual ~EventHandler() {}
};

}
}
#endif /* EVENT_HANDLER_HPP_ */
