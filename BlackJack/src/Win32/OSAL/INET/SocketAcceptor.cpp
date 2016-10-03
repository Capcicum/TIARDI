/*
 * SocketAcceptor.cpp
 *
 *  Created on: 3. okt. 2016
 *      Author: Andersen
 */

#include <OSAL/INET/SocketAcceptor.hpp>

namespace OSAL {
namespace INET {

SocketAcceptor::SocketAcceptor() :
socket(INVALID_SOCKET)
{

}

SocketAcceptor::SocketAcceptor(const INETAddr &addr) :
socket(INVALID_SOCKET)
{
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	result = createSocket();
	if(result == SOCKACCOK)
		result = bind(addr);
	if(result == SOCKACCOK)
		result = listen();
}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::createSocket()
{
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	socket = ::socket(PF_INET, SOCK_STREAM, 0);
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
	int iResult = 0;
	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	iResult = ::bind(socket, addr.getSocketAddr(), addr.getSize());
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

	SocketAcceptor::SocketAcceptorReturn result = SOCKACCOK;
	result = createSocket();
	if(result == SOCKACCOK)
		result = bind(sock_addr);
	if(result == SOCKACCOK)
		result = listen();
	return result;
}

SocketAcceptor::SocketAcceptorReturn SocketAcceptor::accept(SocketStream &s)
{
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



