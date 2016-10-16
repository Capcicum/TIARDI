/*
 * BlackJackServiceHandler.cpp
 *
 *  Created on: 10. okt. 2016
 *      Author: Andersen
 */

#include <App/BlackJackServerServiceHandler.hpp>
#include <Utilities/Utilities.hpp>

namespace App {

BlackJackServerServiceHandler::BlackJackServerServiceHandler(GameLogic::Table* table, int money) :
		Player(table, money)
{

}
BlackJackServerServiceHandler::~BlackJackServerServiceHandler()
{

}

void BlackJackServerServiceHandler::open()
{
	getTable()->addNewPlayer(this);
}

void BlackJackServerServiceHandler::handleEvent(handle handle, EventHandle::Reactor::EventType et)
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

void BlackJackServerServiceHandler::handleEventString(std::string event)
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

void BlackJackServerServiceHandler::update(GameLogic::Player::ClientUpdates event)
{
	std::string message = "";
	switch(event)
	{
	case DEAL:
		message = Utilities::intToString((int)DEAL) + "-" + getCardsName() + "-" + Utilities::intToString(getCardsTotalValue()) + "-" + getTable()->getDealerCardsName() + "-" + Utilities::intToString(getTable()->getDealersTotalCardValue());
		stream.send(message);
		break;
	case NEWCARD:
		message = Utilities::intToString((int)NEWCARD) + "-" + getCardsName() + "-" + Utilities::intToString(getCardsTotalValue());
		stream.send(message);
		break;
	case DEALERSECONDCARD:
		message = Utilities::intToString((int)DEALERSECONDCARD) + "-" + getTable()->getDealerCardsName() + "-" + Utilities::intToString(getTable()->getDealersTotalCardValue());
		stream.send(message);
		break;
	case DEALERSTAND:
		message = Utilities::intToString((int)DEALERSTAND);
		stream.send(message);
		break;
	case DEALERNEWCARD:
		message = Utilities::intToString((int)DEALERNEWCARD) + "-" + getTable()->getDealerCardsName() + "-" + Utilities::intToString(getTable()->getDealersTotalCardValue());
		stream.send(message);
		break;
	case WON:
		message = Utilities::intToString((int)WON) + "-" + Utilities::intToString(getMoney());
		stream.send(message);
		break;
	case LOST:
		message = Utilities::intToString((int)LOST) + "-" + Utilities::intToString(getMoney());
		stream.send(message);
		break;
	}
}

}


