/*
 * EventType.hpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_EVENTHANDLE_REACTOR_EVENTTYPE_HPP_
#define INCLUDE_EVENTHANDLE_REACTOR_EVENTTYPE_HPP_

namespace EventHandle {
namespace Reactor {

typedef unsigned int EventType;
enum {
	READ_EVENT = 01,
	ACCEPT_EVENT = 01,
	WRITE_EVENT = 02,
	CLOSE_EVENT = 04
};

}}

#endif /* INCLUDE_EVENTHANDLE_REACTOR_EVENTTYPE_HPP_ */
