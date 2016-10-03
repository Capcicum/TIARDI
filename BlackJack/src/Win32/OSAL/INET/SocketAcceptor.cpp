/*
 * SocketAcceptor.cpp
 *
 *  Created on: 3. okt. 2016
 *      Author: Andersen
 */

#include <OSAL/INET/SocketAcceptor.hpp>

namespace OSAL {
namespace INET {

SocketAcceptor::SocketAcceptor()
{

}

SocketAcceptor::SocketAcceptor(const INETAddr &addr)
{

}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::createSocket()
{
	int iResult;
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	//socket = socket(PF_INET, SOCK_STREAM, 0);
	if(socket == INVALID_SOCKET)
	{
		result = getError();
	}
	return result;
}

void SocketAcceptor::closeSocket()
{
	closesocket(socket);
}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::bind(const INETAddr &addr)
{
	int iResult;
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	/*iResult = ::bind(socket, addr.getSocketAddr(), addr.getSize());
	sockaddr_t t = addr.getSocketAddr();*/
	if(iResult == SOCKET_ERROR)
	{
		result = getError();
	}
	return result;
}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::listen()
{
	int iResult;
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	iResult = ::listen(socket, SOMAXCONN);
	if(iResult == SOCKET_ERROR)
	{
		result = getError();
		closeSocket();
	}
	return result;
}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::open(CONST INETAddr &sock_addr)
{
	int iResult;
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	return result;
}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::accept(SocketStream &s)
{
	int iResult;
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	socket_t sock;
	sock = ::accept(socket, NULL, NULL);
	if(sock == INVALID_SOCKET)
	{
		result = getError();
		closeSocket();
	}
	else
	{
		s.setSocket(sock);
	}
	return result;
}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::getError()
{
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCERROR;
	return result;
}

}
}



