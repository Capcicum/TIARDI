/*
 * Reactor.cpp
 *
 *  Created on: 8. okt. 2016
 *      Author: Andersen
 */

#include <EventHandle/Reactor/Reactor.hpp>
#include <OSAL/Demux/Demux.hpp>

namespace EventHandle {
namespace Reactor {

Reactor::Reactor(OSAL::Demux::Demux *mux) :
		demux(mux)
{

}

void Reactor::registerHandler(EventHandler *eh, EventType et)
{
	EventHS evhs = {eh, et};
	handle h = eh->getHandle();
	auto aSearch = table.find(h);
	if(aSearch == table.end())
		table[h] = evhs;
	for(auto i= table.begin(); i != table.end(); i++)
	{
		std::cout << (i->first) << std::endl;
	}
}

void Reactor::removeHandler(EventHandler *eh, EventType et)
{
	handle h = eh->getHandle();
	auto aSearch = table.find(h);
	if(aSearch != table.end())
		table.erase(aSearch);
}

void Reactor::handleEvents(int timeout)
{
	std::vector<handle> readFds;
	std::vector<handle> writeFds;
	std::vector<handle> exceptFds;

	for(auto i = table.begin(); i != table.end(); i++)
	{
		if(i->second.evt == EventHandle::Reactor::READ_EVENT || i->second.evt == EventHandle::Reactor::ACCEPT_EVENT)
		{
			readFds.push_back(i->first);
		}
		else if (i->second.evt == EventHandle::Reactor::WRITE_EVENT)
		{
			writeFds.push_back(i->first);
		}
		else
		{
			exceptFds.push_back(i->first);
		}
	}

	int result = demux->handle_events(readFds, writeFds, exceptFds, timeout);
	std::cout << result << std::endl;

	for(auto iRead = readFds.begin(); iRead != readFds.end(); iRead++)
	{
		std::cout <<"read"<<std::endl;
		auto search = table.find(*iRead);
		if(search != table.end())
		{
			search->second.evh->handleEvent(*iRead, EventHandle::Reactor::READ_EVENT);
		}
	}

	for(auto iWrite = writeFds.begin(); iWrite != writeFds.end(); iWrite++)
	{
		std::cout <<"write"<<std::endl;

		auto search = table.find(*iWrite);
		if(search != table.end())
		{
			search->second.evh->handleEvent(*iWrite, EventHandle::Reactor::WRITE_EVENT);
		}
	}

	for(auto iExcept = exceptFds.begin(); iExcept != exceptFds.end(); iExcept++)
	{
		std::cout <<"except"<<std::endl;

		auto search = table.find(*iExcept);
		if(search != table.end())
		{
			search->second.evh->handleEvent(*iExcept, EventHandle::Reactor::CLOSE_EVENT);
		}
	}


}


}}
