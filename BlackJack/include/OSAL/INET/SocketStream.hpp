/*
 * SocketStream.hpp
 *
 *  Created on: 29. sep. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_SOCKETSTREAM_HPP_
#define INCLUDE_OSAL_SOCKETSTREAM_HPP_

#include <DataType.hpp>
#include <String>

namespace OSAL {
namespace INET {
class SocketStream
{
public:

	enum SocketStreamError
	{
		SOCKETOK = 0,
		SOCKETNOTCONNECTED,
		SOCKETNETDOWN,
		SOCKETSHUTDOWN,
		SOCKETHOSTUNREACH,
		SOCKETTIMEDOUT,
		SOCKETERROR

	};

	SocketStream();
	SocketStream(Socket_t sock);
	~SocketStream();
	void setSocket(Socket_t sock);
	Socket_t getSocket();
	SocketStreamError send(std::string msg);
	SocketStreamError receive(std::string& msg);
	SocketStreamError getError();
private:
	Socket_t socket;

};

}}

#endif /* INCLUDE_OSAL_SOCKETSTREAM_HPP_ */
