/*
 * Reactor.hpp
 *
 *  Created on: 14. sep. 2016
 *      Author: Andersen
 */

#ifndef REACTOR_HPP_
#define REACTOR_HPP_

#include "Event_Handler.hpp"
#include "ctime"

class Reactor {
public:
	virtual void register_handler(Event_Handler *eh, Event_Type et) = 0;

	virtual void register_handler(HANDLE h, Event_Handler *eh, Event_Type et) = 0;

	virtual void remove_handler(Event_Handler *eh, Event_Type et) = 0;

	virtual void remove_handler(HANDLE h, Event_Handler *eh, Event_Type et) = 0;

	void handle_events(timeval *timeout = 0);

	static Reactor *instance();

	virtual void ~Reactor();

};



#endif /* REACTOR_HPP_ */
