/*
 * Select.cpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */


#include <OSAL/Demux/IDemux.hpp>
#include <OSAL/Demux/Select.hpp>

namespace OSAL {
namespace Demux {

Select::~Select(){}

int Select::handle_events(
		std::vector<handle>& ioReadFds,
		std::vector<handle>& ioWriteFds,
		std::vector<handle>& ioExceptFds,
		int timeout)
{
	fd_set readFds, writeFds, exceptFds;
	FD_ZERO(&readFds);
	FD_ZERO(&writeFds);
	FD_ZERO(&exceptFds);

	std::for_each(ioReadFds.begin(), ioReadFds.end(), [&readFds](handle i){FD_SET(i, &readFds);});
	std::for_each(ioReadFds.begin(), ioReadFds.end(), [&writeFds](handle i){FD_SET(i, &writeFds);});
	std::for_each(ioReadFds.begin(), ioReadFds.end(), [&exceptFds](handle i){FD_SET(i, &exceptFds);});


    int aMaxReadFd = 0;
    if (!ioReadFds.empty())
    {
        aMaxReadFd = *std::max_element(ioReadFds.begin(), ioReadFds.end());
    }

    int aMaxWriteFd = 0;
    if (!ioWriteFds.empty())
    {
        aMaxWriteFd = *std::max_element(ioWriteFds.begin(), ioWriteFds.end());
    }

    int aMaxExceptFd = 0;
    if (!ioExceptFds.empty())
    {
        aMaxExceptFd = *std::max_element(ioExceptFds.begin(), ioExceptFds.end());
    }

    int aMax = (std::max)(aMaxReadFd, (std::max)(aMaxWriteFd, aMaxExceptFd));

    // timeout conversion
    timeval timeoutval;
    timeoutval.tv_sec = timeout;
    timeoutval.tv_usec = 0;

    // The system call to 'select()'
    int result = ::select(aMax+1, &readFds, &writeFds, &exceptFds, &timeoutval);

    // Filter the ready for I/O fds.
    ioReadFds.erase(
    		std::remove_if(
    				ioReadFds.begin(),
					ioReadFds.end(),
    				[&readFds](handle i){return FD_ISSET(i, &readFds) == 1;}),
			ioReadFds.end());

    ioWriteFds.erase(
    		std::remove_if(
    				ioWriteFds.begin(),
					ioWriteFds.end(),
					[&writeFds](handle i){return FD_ISSET(i, &writeFds) == 1;}),
			ioWriteFds.end());

    ioExceptFds.erase(
    		std::remove_if(
    				ioExceptFds.begin(),
    				ioExceptFds.end(),
					[&exceptFds](handle i){return FD_ISSET(i, &exceptFds) == 1;}),
			ioExceptFds.end());

   return result;
}



}}


