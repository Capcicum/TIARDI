/*
 * IDemux.hpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_DEMUX_IDEMUX_HPP_
#define INCLUDE_OSAL_DEMUX_IDEMUX_HPP_

#include <vector>
#include <DataType.hpp>

namespace OSAL {
namespace Demux {

class IDemux
{
public:
	virtual ~IDemux(){}
	virtual int handle_events(
			std::vector<handle>& ioReadFds,
			std::vector<handle>& ioWriteFds,
			std::vector<handle>& ioExceptFds,
			int timeout = 0) = 0;
};

}
}


#endif /* INCLUDE_OSAL_DEMUX_IDEMUX_HPP_ */
