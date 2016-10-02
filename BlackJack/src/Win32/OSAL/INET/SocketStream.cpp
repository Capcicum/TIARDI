/*
 * SocketStream.cpp
 *
 *  Created on: 29. sep. 2016
 *      Author: Andersen
 */

#include <OSAL/INET/SocketStream.hpp>
#include <vector>

namespace OSAL {
namespace INET {

SocketStream::SocketStream() :
socket(INVALID_SOCKET)
{}

SocketStream::SocketStream(Socket_t sock) :
socket(sock)
{}

SocketStream::~SocketStream()
{
	closesocket(socket);
}

void SocketStream::setSocket(Socket_t sock)
{
	socket = sock;
}

Socket_t SocketStream::getSocket()
{
	return socket;
}

u_int64 SocketStream::send(std::string msg)
{
	u_int64 result = 0;
	result = ::send(socket, msg.c_str(), msg.size(), 0);
	return result;
}

u_int64 SocketStream::receive(std::string& msg)
{
	int64 result = 0;
	const unsigned int MAX_BUF_LENGTH = 4096;
	std::vector<char> buffer(MAX_BUF_LENGTH);
	do {
		result = recv(socket, buffer.data(), buffer.size(), 0);
	    // append string from buffer.
	    if ( result == -1 ) {
	        // error
	    } else {
	        msg.append( buffer.cbegin(), buffer.cend() );
	    }
	} while ( result == MAX_BUF_LENGTH );
	return 0;
}

}}
