/*
 * ReactorFactory.cpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#include <EventHandle/Reactor/ReactorFactory.hpp>
#include <OSAL/Demux/Select.hpp>

namespace EventHandle {
namespace Reactor {

ReactorFactory::ReactorFactory(DemuxImpl impl) :
		reactor(nullptr)
{
	switch (impl)
	{
	case SELECT:
		demuxImpl = new OSAL::Demux::Select();
		demux = new OSAL::Demux::Demux(demuxImpl);
		break;
	default:
		break;
	}
}

ReactorFactory::~ReactorFactory()
{
	if (reactor)
	{
		delete reactor;
	}
	delete demux;
	delete demuxImpl;
}

Reactor* ReactorFactory::instance()
{
	if (!reactor) {
		reactor = new Reactor(demux);
	}
	return reactor;
}

}
}


