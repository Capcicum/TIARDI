/*
 * client.cpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */


#include <OSAL/INET/SocketConnector.hpp>
#include <OSAL/INET/SocketStream.hpp>
#include <OSAL/INET/INETAddr.hpp>
#include <iostream>
#include "OSAL/Win32/INET/WSA.hpp"
#include <DataType.hpp>
#include <winsock2.h>

int main()
{
	WSA wsa;
	if(wsa.startUp() == WSA::WSAOK)
	{
		OSAL::INET::SocketConnector* socketConnector = new OSAL::INET::SocketConnector();
		OSAL::INET::SocketStream* socketStream = new OSAL::INET::SocketStream();
		OSAL::INET::INETAddr* addr = new OSAL::INET::INETAddr(27015, inet_addr("127.0.0.1"));

		std::cout << "Initialised" << std::endl;
		/*std::cout << socketStream->getSocket() << std::endl;
		SOCKET s = socketStream->getSocket();

		handle_t h = static_cast<handle_t>(&s);
		socket_t *check = static_cast<socket_t*>(h);

		std::cout << *check << std::endl;*/

		std::cout << "connecting" << std::endl;
		if(socketConnector->connect(*addr, *socketStream) == OSAL::INET::SocketConnector::SOCKCONOK)
		{
			std::cout << "connected" << std::endl;
		}
		else
		{
			printf("connect failed with error: %d\n", WSAGetLastError());
			std::cout << "error" << std::endl;
		}

		while(true)
		{
			std::string msg = "";
			std::cout << "input word:" << std::endl;
			std::getline(std::cin, msg);
			std::cout << msg << std::endl;
			if(socketStream->send(msg) == OSAL::INET::SocketStream::SOCKETOK)
			{
				std::cout << "send" << std::endl;
			}
			else
			{
				std::cout << "error" << std::endl;
			}
		}

	}
	return 0;
}
