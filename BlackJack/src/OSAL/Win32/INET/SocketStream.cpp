/*
 * SocketStream.cpp
 *
 *  Created on: 29. sep. 2016
 *      Author: Andersen
 */

#include <OSAL/INET/SocketStream.hpp>
#include <iostream>

namespace OSAL {
namespace INET {

SocketStream::SocketStream() :
socket(INVALID_SOCKET)
{}

SocketStream::SocketStream(socket_t sock) :
socket(sock)
{}

SocketStream::~SocketStream()
{
	closesocket(socket);
}

void SocketStream::setSocket(socket_t sock)
{
	socket = sock;
}

handle SocketStream::getHandle() const
{
	return socket;
}

SocketStream::SocketStreamError SocketStream::send(std::string msg)
{
	int64 sendSize = 0;
	SocketStream::SocketStreamError result = SOCKETOK;
	sendSize = ::send(socket, msg.c_str(), msg.size(), 0);
	if(sendSize == SOCKET_ERROR)
		result = getError();
	return result;
}

SocketStream::SocketStreamError SocketStream::receive(std::string& msg)
{
	int64 recvSize;
	SocketStream::SocketStreamError result = SOCKETOK;
	char buffer[1024];

	recvSize = recv(socket, buffer, sizeof(buffer), 0);
	if(recvSize != INVALID_SOCKET || recvSize != SOCKET_ERROR)
	{
		if(recvSize > 0)
		{
			msg.append(buffer, recvSize);
		}
		else
		{
			result = SocketStream::SOCKETNOTCONNECTED;
		}
	}
	else
	{
		result = getError();
	}
	return result;
}

SocketStream::SocketStreamError SocketStream::getError()
{
	int16 error = 0;
	SocketStream::SocketStreamError result;

	error = WSAGetLastError();

	switch(error)
	{
	case WSAENOTCONN:
		result = SOCKETNOTCONNECTED;
		break;
	case WSAENETDOWN:
		result = SOCKETNETDOWN;
		break;
	case WSAESHUTDOWN:
		result = SOCKETSHUTDOWN;
		break;
	case WSAEHOSTUNREACH:
		result = SOCKETHOSTUNREACH;
		break;
	case WSAETIMEDOUT:
		result = SOCKETTIMEDOUT;
		break;
	default:
		result = SOCKETERROR;
	}
	return result;
}

}}
