/*
 * Connector.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include <EventHandle/AccConn/Connector.hpp>

namespace EventHandle {
namespace AccConn {

template<class SERVICEHANDLER, class IPCCONNECTOR>
Connector<SERVICEHANDLER,IPCCONNECTOR>::Connector(Reactor::Reactor* r)
{

}

template<class SERVICEHANDLER, class IPCCONNECTOR>
void Connector<SERVICEHANDLER,IPCCONNECTOR>::connect(SERVICEHANDLER *sh, const Addr &remoteAddr)
{
	connectServiceHandler(sh, remoteAddr);
}


}}


