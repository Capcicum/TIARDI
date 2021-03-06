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
	/**
	 * @brief - select constructor
	 */
	~Select();

	/**
	 * @brief - takes a number of vectors with handles and return
	 * the same vector but only with the handles that are ready
	 * @param ioReadFds - Vector containing all handles for read
	 * @param ioWriteFds - vector containgen all handles for write
	 * @param ioExceptFds - Vector containing all handle for except
	 * @param timeout - the timeout of the function
	 */
	int handle_events(
			std::vector<handle>& ioReadFds,
			std::vector<handle>& ioWriteFds,
			std::vector<handle>& ioExceptFds,
			int timeout = 0);

};


}}



#endif /* INCLUDE_OSAL_DEMUX_SELECT_HPP_ */
