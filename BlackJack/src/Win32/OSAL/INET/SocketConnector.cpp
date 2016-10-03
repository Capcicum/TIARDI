/*
 * SocketConnector.cpp
 *
 *  Created on: 3. okt. 2016
 *      Author: Andersen
 */

#include <OSAL/INET/SocketConnector.hpp>

namespace OSAL {
namespace INET {

SocketConnector::SocketConnector() :
		socket(INVALID_SOCKET)
{
	createSocket();
}

SocketConnector::SocketConnectorReturn SocketConnector::createSocket()
{
	SocketConnector::SocketConnectorReturn result = SOCKCONOK;
	socket = ::socket(PF_INET, SOCK_STREAM, 0);
	if(socket == INVALID_SOCKET)
	{
		result = getError();
	}
	return result;
}

void SocketConnector::closeSocket()
{
	::closesocket(socket);
}

SocketConnector::SocketConnectorReturn SocketConnector::connect(const INETAddr &addr, SocketStream &s)
{
	int iResult = 0;
	SocketConnector::SocketConnectorReturn result = SOCKCONOK;
	iResult = ::connect(socket, addr.getSocketAddr(), addr.getSize());
	if(iResult == SOCKET_ERROR)
	{
		result = getError();
		closeSocket();
	}
	s.setSocket(socket);
	return result;
}

SocketConnector::SocketConnectorReturn SocketConnector::getError()
{
	SocketConnector::SocketConnectorReturn result = SOCKCONOK;
	return result;
}


}}
