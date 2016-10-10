/*
 * Demux.hpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_DEMUX_DEMUX_HPP_
#define INCLUDE_OSAL_DEMUX_DEMUX_HPP_

#include <OSAL/Demux/IDemux.hpp>

namespace OSAL {
namespace Demux {

class Demux
{
public:
	Demux(IDemux* mux);
	int handle_events(
			std::vector<handle>& ioReadFds,
			std::vector<handle>& ioWriteFds,
			std::vector<handle>& ioExceptFds,
			int timeout = 0);
private:
	IDemux* demux;

};

}
}



#endif /* INCLUDE_OSAL_DEMUX_DEMUX_HPP_ */
