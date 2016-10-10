/*
 * Demux.cpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */

#include <OSAL/Demux/Demux.hpp>

namespace OSAL {
namespace Demux {

Demux::Demux(IDemux* mux) :
		demux(mux)
{

}

int Demux::handle_events(
		std::vector<handle>& ioReadFds,
		std::vector<handle>& ioWriteFds,
		std::vector<handle>& ioExceptFds,
		int timeout)
{
	return demux->handle_events(ioReadFds, ioWriteFds, ioExceptFds, timeout);
}

}
}
