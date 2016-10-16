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

	/**
	 *@brief - INETAddr class constructor
	 *@param port - the port
	 *@param addr - the IP addr
	 */
	INETAddr(u_int16 port, u_int32 addr);

	/**
	 *@brief - returns the port
	 *@return - return the port
	 */
	u_int16 getPort() const;

	/**
	 *@brief - returns the IP addr
	 *@return - returns the IP addr
	 */
	u_int32 getIPAddr() const;

	/**
	 *@brief - gets the size of the addr
	 *@return - returns the addr of the addr
	 */
	u_int64 getSize() const;

	/**
	 *@brief - returns the object as an sockaddr_t
	 *@return - return the object as an sockaddr_t
	 */
	sockaddr_t* getSocketAddr() const;

private:
	sockaddrIn_t sockaddr;

};

}}


#endif /* INCLUDE_OSAL_WIN32_INET_ADDR_HPP_ */
