/*
 * SocketConnector.hpp
 *
 *  Created on: 3. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_INET_SOCKETCONNECTOR_HPP_
#define INCLUDE_OSAL_INET_SOCKETCONNECTOR_HPP_

#include <DataType.hpp>
#include <OSAL/INET/INETAddr.hpp>
#include <OSAL/INET/SocketStream.hpp>

namespace OSAL {
namespace INET {

class SocketConnector
{
public:
	enum SocketConnectorReturn
	{
		SOCKCONOK = 0,
		SOCKCONERROR
	};
	SocketConnector();
	SocketConnectorReturn createSocket();
	void closeSocket();
	SocketConnectorReturn connect(const INETAddr &addr, SocketStream &s);
	SocketConnectorReturn getError();
private:
	socket_t socket;
};

}}



#endif /* INCLUDE_OSAL_INET_SOCKETCONNECTOR_HPP_ */