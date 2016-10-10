/*
 * Select.hpp
 *
 *  Created on: 7. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_DEMUX_SELECT_HPP_
#define INCLUDE_OSAL_DEMUX_SELECT_HPP_

#include <OSAL/Demux/IDemux.hpp>
#include <algorithm>
#include <functional>
#include <DataType.hpp>

namespace OSAL {
namespace Demux {

class Select : public IDemux
{
public:
	~Select();

	int handle_events(
			std::vector<handle>& ioReadFds,
			std::vector<handle>& ioWriteFds,
			std::vector<handle>& ioExceptFds,
			int timeout = 0);

};


}}



#endif /* INCLUDE_OSAL_DEMUX_SELECT_HPP_ */
