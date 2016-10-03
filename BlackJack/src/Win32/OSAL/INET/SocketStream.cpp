/*
 * SocketStream.cpp
 *
 *  Created on: 29. sep. 2016
 *      Author: Andersen
 */

#include <OSAL/INET/SocketStream.hpp>

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

socket_t SocketStream::getSocket()
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
	int64 recvSize = 0;
	SocketStream::SocketStreamError result = SOCKETOK;
	bool readMore = true;
	do {
		char singleChar = 0;
		recvSize = recv(socket, &singleChar, 1, 0);
	    if(recvSize != INVALID_SOCKET && recvSize != SOCKET_ERROR)
	    {
	    	if(singleChar == '\n')
	    		readMore = false;
	    	else
	    		msg += singleChar;
	    }
	    else
	    {
	    	result = getError();
	    }
		} while ( readMore );
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
