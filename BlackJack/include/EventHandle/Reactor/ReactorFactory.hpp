/*
 * ReactorFactory.hpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_EVENTHANDLE_REACTOR_REACTORFACTORY_HPP_
#define INCLUDE_EVENTHANDLE_REACTOR_REACTORFACTORY_HPP_

#include <EventHandle/Reactor/Reactor.hpp>
#include <OSAL/Demux/Select.hpp>

namespace EventHandle {
namespace Reactor {

class ReactorFactory
{
public:

	enum DemuxImpl
	{
		SELECT = 0
	};

	/**
	 * @brief - Creates the ReactorFactory
	 * @param impl -  A enum value to specify which concrete implementation of the demux to use
	 */
	ReactorFactory(DemuxImpl impl);

	/**
	 * @brief - The ReactorFactorys destructor
	 */
	~ReactorFactory();

	/**
	 * @brief - returns an instance of a reactor.
	 * @return - A pointer to a reactor instance
	 */
	Reactor* instance();
private:
	OSAL::Demux::IDemux* demuxImpl;
	OSAL::Demux::Demux* demux;
	Reactor* reactor;

};
}
}



#endif /* INCLUDE_EVENTHANDLE_REACTOR_REACTORFACTORY_HPP_ */
