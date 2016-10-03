/*
 * SocketAcceptor.hpp
 *
 *  Created on: 28. sep. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_WIN32_SOCKETACCEPTOR_HPP_
#define INCLUDE_OSAL_WIN32_SOCKETACCEPTOR_HPP_

#include <OSAL/INET/INETAddr.hpp>
#include <OSAL/INET/SocketStream.hpp>
#include <DataType.hpp>

namespace OSAL {
namespace INET {

class SocketAcceptor {
public:
	enum SocketAcceptorReturn
	{
		SOCKACCOK = 0,
		SOCKACCERROR
	};
	SocketAcceptor();
	SocketAcceptor(const INETAddr &addr);
	SocketAcceptorReturn createSocket();
	void closeSocket();
	SocketAcceptorReturn bind(const INETAddr &addr);
	SocketAcceptorReturn listen();
	SocketAcceptorReturn open(CONST INETAddr &sock_addr);
	SocketAcceptorReturn accept(SocketStream &s);
	SocketAcceptorReturn getError();
private:
	socket_t socket;
};

}}


#endif /* INCLUDE_OSAL_WIN32_SOCKETACCEPTOR_HPP_ */
