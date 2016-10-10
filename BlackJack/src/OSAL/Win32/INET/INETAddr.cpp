/*
 * INETAddr.cpp
 *
 *  Created on: 28. sep. 2016
 *      Author: Andersen
 */

#include <OSAL/INET/INETAddr.hpp>

namespace OSAL {
namespace INET {

	INETAddr::INETAddr(u_int16 port, u_int32 addr)
	{
		memset(&sockaddr, 0, sizeof sockaddr);
		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = addr;
		sockaddr.sin_port = htons(port);
	}

	u_int16 INETAddr::getPort() const
	{
		return sockaddr.sin_port;
	}

	u_int32 INETAddr::getIPAddr() const
	{
		return sockaddr.sin_addr.s_addr;
	}

	sockaddr_t* INETAddr::getSocketAddr() const
	{
		return (sockaddr_t*)&sockaddr;
	}

	u_int64 INETAddr::getSize() const
	{
		return sizeof (sockaddr);
	}

}}
