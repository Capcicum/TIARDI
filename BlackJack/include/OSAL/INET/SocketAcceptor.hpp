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
	typedef INETAddr PEERADDR;
	enum SocketAcceptorReturn
	{
		SOCKACCOK = 0,
		SOCKACCERROR
	};
	SocketAcceptor();
	SocketAcceptor(const PEERADDR &addr);
	SocketAcceptorReturn createSocket();
	void closeSocket();
	handle getHandle() const;
	SocketAcceptorReturn bind(const PEERADDR &addr);
	SocketAcceptorReturn listen();
	SocketAcceptorReturn open(CONST PEERADDR &sock_addr);
	SocketAcceptorReturn accept(SocketStream &s);
	SocketAcceptorReturn getError();
private:
	socket_t socket;
};

}}


#endif /* INCLUDE_OSAL_WIN32_SOCKETACCEPTOR_HPP_ */
