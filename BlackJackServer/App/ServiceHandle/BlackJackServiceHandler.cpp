/*
 * BlackJackServiceHandler.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include "BlackJackServiceHandler.hpp"

namespace App {
namespace ServiceHandle {

BlackJackServiceHandler::BlackJackServiceHandler(GameLogic::Table* table, int money) :
		Player(table, money)
{

}
BlackJackServiceHandler::~BlackJackServiceHandler()
{

}

void BlackJackServiceHandler::open()
{

}

void BlackJackServiceHandler::handleEvent(handle handle, EventHandle::Reactor::EventType et)
{
	if(et == EventHandle::Reactor::READ_EVENT)
	{
		std::string msg = "";
		if(stream.receive(msg) == OSAL::INET::SocketStream::SOCKETOK)
		{
			handleEventString(msg);
		}
	}
}

void BlackJackServiceHandler::handleEventString(std::string event)
{
	clientEvents eventType = (clientEvents)atoi(std::string(1, event.at(0)).c_str());
	switch(eventType)
	{
	case BET:
	{
		int betValue = atoi(event.substr(2, event.size()-2).c_str());
		bet(betValue);
		break;
	}
	case HIT:
		hit();
		break;
	case STAND:
		stand();
		break;
	case STOP:
		break;
	}

}

void BlackJackServiceHandler::update(GameLogic::Player::ClientUpdates event)
{
	std::string message = "";
	switch(event)
	{
	case DEAL:
		message = intToString((int)DEAL) + "-" + getCardsNames() + "-" + intToString(getCardsTotalValue()) + "-" + table->getDealerCardsName() + "-" + intToString(table->getDealersTotalCardValue());
		stream.send(message);
		break;
	case DEALERFIRSTCARD:
		message = intToString((int)DEALERFIRSTCARD) + "-" + table->getDealerCardsName() + "-" + intToString(table->getDealersTotalCardValue());
		stream.send(message);
		break;
	case STARTHITTING:
		message = intToString((int)STARTHITTING) + "-" + intToString(getCardsTotalValue());
		stream.send(message);
		break;
	case NEWCARD:
		message = intToString((int)NEWCARD) + "-" + getCardsNames() + "-" + intToString(getCardsTotalValue());
		stream.send(message);
		break;
	case DEALERSECONDCARD:
		message = intToString((int)DEALERSECONDCARD) + "-" + table->getDealerCardsName() + "-" + intToString(table->getDealersTotalCardValue());
		stream.send(message);
		break;
	case DEALERSTAND:
		message = intToString((int)DEALERSTAND);
		stream.send(message);
		break;
	case DEALERNEWCARD:
		message = intToString((int)DEALERNEWCARD) + "-" + table->getDealerCardsName() + "-" + intToString(table->getDealersTotalCardValue());
		stream.send(message);
		break;
	case WON:
		message = intToString((int)WON) + "-" + intToString(getMoney());
		stream.send(message);
		break;
	case LOST:
		message = intToString((int)LOST) + "-" + intToString(getMoney());
		stream.send(message);
		break;
	}
}

std::string BlackJackServiceHandler::intToString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

}}


