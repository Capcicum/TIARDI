/*
 * Reactor.hpp
 *
 *  Created on: 14. sep. 2016
 *      Author: Andersen
 */

#ifndef REACTOR_HPP_
#define REACTOR_HPP_

#include <EventHandle/Reactor/EventHandler.hpp>
#include <map>
#include <OSAL/Demux/IDemux.hpp>
#include <OSAL/Demux/Demux.hpp>

namespace EventHandle {
namespace Reactor {

class Reactor {
public:

	/**
	 * @brief - Constructor for the reactor
	 * @param mux - a pointer to a Demux object
	 */
	Reactor(OSAL::Demux::Demux *mux);

	/**
	 * @brief - registers a eventHandler in the reactors handle set
	 * @param eh - the event handler to register
	 * @param et - the event type for the eventhandler
	 */
	void registerHandler(EventHandler *eh, EventType et);

	/**
	 * @brief - removes a event handler form the handle set
	 * @param eh - a pointer to the eventhandler to remove
	 * @param et - the event type to remove form the event handler in the handle set
	 */
	void removeHandler(EventHandler *eh, EventType et);

	/**
	 * @brief - the reactor event loop where it demultiplexes and dispatches the handles to the sssociated eventhandlers
	 * @param timeout - the timeout to parse to the demux
	 */
	void handleEvents(int timeout = 0);

private:

	/**
	 * Struct used to associate an event handler with event types
	 */
	struct EventHS
	{
		EventHandler* evh;
		EventType evt;
	};

	typedef std::map<handle, EventHS> tableMap; //handle set

	tableMap table; //handle set

	OSAL::Demux::Demux *demux;

};

}
}

#endif /* REACTOR_HPP_ */
