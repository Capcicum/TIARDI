/*
 * WSA.cpp
 *
 *  Created on: 6. okt. 2016
 *      Author: Andersen
 */

#include <DataType.hpp>
#include "WSA.hpp"

WSA::WSA()
{

}

WSA::~WSA()
{
	cleanUp();
}

WSA::WSAError WSA::startUp()
{
	int iResult = 0;
	WSA::WSAError result = WSA::WSAOK;
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if(iResult != 0)
		result = getError();
	return result;
}

WSA::WSAError WSA::getError()
{
	int16 error = 0;
	WSA::WSAError result;

	error = WSAGetLastError();

	switch(error)
	{
	case WSASYSNOTREADY:
		result = WSASYSTEMNOTREADY;
		break;
	case WSAVERNOTSUPPORTED:
		result = WSAVERSIONNOTSUPPORTED;
		break;
	case WSAEINPROGRESS:
		result = WSAINPROGRESS;
		break;
	case WSAEPROCLIM:
		result = WSAPROCLIM;
		break;
	case WSAEFAULT:
		result = WSAFAULT;
		break;
	default:
		result = WSAERROR;
	}
	return result;
}

void WSA::cleanUp()
{
	WSACleanup();
}

