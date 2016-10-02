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
	SocketStream();
	SocketStream(Socket_t sock);
	~SocketStream();
	void setSocket(Socket_t sock);
	Socket_t getSocket();
	u_int64 send(std::string msg);
	u_int64 receive(std::string& msg);
private:
	Socket_t socket;

};

}}

#endif /* INCLUDE_OSAL_SOCKETSTREAM_HPP_ */
