/*
 * Event_Handler.hpp
 *
 *  Created on: 14. sep. 2016
 *      Author: Andersen
 */

#ifndef EVENT_HANDLER_HPP_
#define EVENT_HANDLER_HPP_

#include <iostream>
#include <WinNT.h>

typedef unsigned int Event_Type;
enum {
	READ_EVENT = 01,
	ACCEPT_EVENT = 01,
	WRITE_EVENT = 02,
	TIMEOUT_EVENT= 04,
	SIGNAL_EVENT = 010,
	CLOSE_EVENT = 020
};

class Event_Handler {
public:
	virtual void handle_event(HANDLE handle, Event_Type et) = 0;

	virtual HANDLE getHandle() const = 0;

protected:
	virtual ~Event_Handler();
};

#endif /* EVENT_HANDLER_HPP_ */
