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
	Reactor(OSAL::Demux::Demux *mux);

	void registerHandler(EventHandler *eh, EventType et);

	void removeHandler(EventHandler *eh, EventType et);

	void handleEvents(int timeout = 0);

private:
	struct EventHS
	{
		EventHandler* evh;
		EventType evt;
	};
	typedef std::map<handle, EventHS> tableMap;
	tableMap table;
	OSAL::Demux::Demux *demux;

};

}
}


#endif /* REACTOR_HPP_ */
