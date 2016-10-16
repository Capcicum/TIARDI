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

	/**
	 * @brief - socketStream constructor
	 */
	SocketStream();

	/**
	 * @brief - socketstream constructor and sets the socket
	 * @param - the socket to set
	 */
	explicit SocketStream(socket_t sock);

	/**
	 * @brief -
	 */
	~SocketStream();

	/**
	 * @brief -
	 */
	void setSocket(socket_t sock);

	/**
	 * @brief -
	 */
	handle getHandle() const;

	/**
	 * @brief -
	 */
	SocketStreamError send(std::string msg);

	/**
	 * @brief -
	 */
	SocketStreamError receive(std::string& msg);

	/**
	 * @brief -
	 */
	SocketStreamError getError();
private:
	socket_t socket;

};

}}

#endif /* INCLUDE_OSAL_SOCKETSTREAM_HPP_ */
