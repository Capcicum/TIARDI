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
#include <ws2tcpip.h>
#include <stdlib.h>
#include <cstdio>

#include <GameLogic/Table.hpp>
#include <GameLogic/Card.hpp>

using namespace GameLogic;

class PlayerClass : public Player
{
public:
	PlayerClass(Table* table, int money = 200) : Player(table, money){}
	void update()
	{
		std::cout << table->getDealerCardsName() << std::endl;
	}
};


int main()
{

	std::string in;
	Table* table = new Table();
	PlayerClass* player = new PlayerClass(table);
	table->addNewPlayer(player);
	player->bet(100);
	std::cout << player->getCardsNames() << std::endl;

	while (player->getIsHitting()) {
		std::cin >> in;
		if (in == "hit") {
			player->hit();
			std::cout << player->getCardsNames() << std::endl;
		} else if (in == "stand") {
			player->stand();
		}
	}


	/*WSA wsa;
	if(wsa.startUp() == WSA::WSAOK)
	{
		OSAL::INET::SocketConnector* socketConnector = new OSAL::INET::SocketConnector();
		OSAL::INET::SocketStream* socketStream = new OSAL::INET::SocketStream();
		OSAL::INET::INETAddr* addr = new OSAL::INET::INETAddr(27015, inet_addr("198.168.189.27"));

		std::cout << "Initialised" << std::endl;
		/*std::cout << socketStream->getSocket() << std::endl;
		SOCKET s = socketStream->getSocket();

		handle_t h = static_cast<handle_t>(&s);
		socket_t *check = static_cast<socket_t*>(h);

		std::cout << *check << std::endl;

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
		struct sockaddr_storage saddr;
		socklen_t len = sizeof saddr;
		getpeername(socketStream->getHandle(), (struct sockaddr*)&addr, &len);
	    struct sockaddr_in *s = (struct sockaddr_in *)&addr;
	    int port = ntohs(s->sin_port);

	    printf("Peer IP address: %s\n", inet_ntoa(s->sin_addr));
	    printf("Peer port      : %d\n", port);

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

	}*/
	return 0;
}
