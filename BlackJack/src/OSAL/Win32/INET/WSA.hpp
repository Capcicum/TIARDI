/*
 * WSA.hpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */

#ifndef SRC_WIN32_OSAL_INET_WSA_HPP_
#define SRC_WIN32_OSAL_INET_WSA_HPP_

#include <DataType.hpp>

class WSA
{
public:
	enum WSAError
	{
		WSAOK = 0,
		WSASYSTEMNOTREADY,
		WSAVERSIONNOTSUPPORTED,
		WSAINPROGRESS,
		WSAPROCLIM,
		WSAFAULT,
		WSAERROR
	};

	WSA();
	~WSA();
	WSAError startUp();
	WSAError getError();
	void cleanUp();
private:
	WSADATA wsaData;
};



#endif /* SRC_WIN32_OSAL_INET_WSA_HPP_ */
