/*
 * ServiceHandler.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include <EventHandle/AccConn/ServiceHandler.hpp>


namespace EventHandle {
namespace AccConn {

template <class IPC_STREAM>
IPC_STREAM& ServiceHandler<IPC_STREAM>::peer()
{
	return stream;
}

template <class IPC_STREAM>
std::string ServiceHandler<IPC_STREAM>::remoteAddr()
{

}

template <class IPC_STREAM>
void ServiceHandler<IPC_STREAM>::setHandle(handle h)
{
	stream.setHandle(h);
}


}}

