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

	virtual ~EventHandler() {}

	/**
	 * @brief Handles the handle after the EventType
	 * @param handle  The READY handle
	 * @param et  The event type which triggered the handle
	 *
	 * Virtual function which when implemented is called by a
	 * reactor when associated handle is READY.
	 */
	virtual void handleEvent(handle handle, EventType et) = 0;


	/**
	 * @brief Returns associated handle
	 * @return The associated handle
	 *
	 * Returns associated handle of the EventHandler
	 */
	virtual handle getHandle() const = 0;

};

}
}
#endif /* EVENT_HANDLER_HPP_ */
