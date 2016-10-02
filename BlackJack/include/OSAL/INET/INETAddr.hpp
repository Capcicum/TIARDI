/*
 * INET_Addr.hpp
 *
 *  Created on: 28. sep. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_WIN32_INET_ADDR_HPP_
#define INCLUDE_OSAL_WIN32_INET_ADDR_HPP_

#include <DataType.hpp>

namespace OSAL {
namespace INET {

class INETAddr {
public:
	INETAddr(u_int16 port, u_int32 addr);

	u_int16 getPort() const;

	u_int32 getIPAddr() const;

	u_int64 getSize() const;

private:
	sockAddr sockaddr;

};

}}


#endif /* INCLUDE_OSAL_WIN32_INET_ADDR_HPP_ */
