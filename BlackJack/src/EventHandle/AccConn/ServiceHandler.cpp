/*
 * ServiceHandler.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include <EventHandle/AccConn/ServiceHandler.hpp>


namespace EventHandle {
namespace AccConn {

template <class IPCSTREAM>
IPCSTREAM& ServiceHandler<IPCSTREAM>::peer()
{
	return stream;
}

template <class IPCSTREAM>
std::string ServiceHandler<IPCSTREAM>::remoteAddr()
{

}

template <class IPCSTREAM>
void ServiceHandler<IPCSTREAM>::setHandle(handle h)
{
	stream.setHandle(h);
}

template <class IPCSTREAM>
handle ServiceHandler<IPCSTREAM>::getHandle() const
{
	return stream.getHandle();
}


}}

