/*
 * DataType.hpp
 *
 *  Created on: 28. sep. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_OSAL_DATATYPE_HPP_
#define INCLUDE_OSAL_DATATYPE_HPP_

typedef unsigned char u_int8;
typedef signed char int8;
typedef unsigned short u_int16;
typedef signed short int16;
typedef unsigned long u_int32;
typedef signed long int32;
typedef unsigned long long u_int64;
typedef signed long long int64;

#ifdef WIN

#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>

typedef sockaddr_in sockAddr;
typedef SOCKET Socket_t;

#endif

#endif /* INCLUDE_OSAL_DATATYPE_HPP_ */
