/*
 * BlackJackPlayer.cpp
 *
 *  Created on: 12. okt. 2016
 *      Author: Andersen
 */

#include "BlackJackPlayer.hpp"

	BlackJackPlayer::BlackJackPlayer()
	{

	}

	BlackJackPlayer::~BlackJackPlayer()
	{

	}

	void BlackJackPlayer::open()
	{
		betting();
	}

	void BlackJackPlayer::handleEvent(handle handle, EventHandle::Reactor::EventType et)
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

	void BlackJackPlayer::handleEventString(std::string event)
	{
		GameLogic::Player::ClientUpdates eventType = (GameLogic::Player::ClientUpdates)atoi(std::string(1, event.at(0)).c_str());

		switch(eventType)
		{
		case GameLogic::Player::DEAL:
			deal(event);
			break;
		case GameLogic::Player::DEALERFIRSTCARD:
			dealerFirstCard(event);
			break;
		case GameLogic::Player::STARTHITTING:
			startHitting(event);
			break;
		case GameLogic::Player::DEALERNEWCARD:
			dealerNewCard(event);
			break;
		case GameLogic::Player::DEALERSECONDCARD:
			dealerSecondCard(event);
			break;
		case GameLogic::Player::DEALERSTAND:
			dealerStand(event);
			break;
		case GameLogic::Player::LOST:
			lost(event);
			break;
		case GameLogic::Player::NEWCARD:
			newCard(event);
			break;
		case GameLogic::Player::WON:
			won(event);
			break;

		}
	}

	std::string BlackJackPlayer::intToString(int value)
	{
		std::stringstream ss;
		ss << value;
		return ss.str();
	}

	int BlackJackPlayer::nthOccurrence(const std::string& str, const std::string& findMe, int nth)
	{
	    size_t  pos = 0;
	    int     cnt = 0;

	    while( cnt != nth )
	    {
	        pos+=1;
	        pos = str.find(findMe, pos);
	        if ( pos == std::string::npos )
	            return -1;
	        cnt++;
	    }
	    return pos;
	}

	void BlackJackPlayer::deal(std::string event)
	{
		std::cout << "All players has placed their bets, and the dealer will now proceed to deal cards." << std::endl;
		std::cout << "Your cards are:" << std::endl;
		std::string cards = event.substr(nthOccurrence(event, "-", 1)+1, nthOccurrence(event, "-", 2)-2);
		std::cout << cards << std::endl;
		std::cout << "The total value of your cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, nthOccurrence(event, "-", 3) - nthOccurrence(event, "-", 2)-1) << std::endl;
		std::cout << "The dealers first card is:" << std::endl;
		std::string card = event.substr(nthOccurrence(event, "-", 3)+1, nthOccurrence(event, "-", 4) - nthOccurrence(event, "-", 3)-1);
		std::cout << card << std::endl;
		std::cout << "The total value the dealers card is: " << event.substr(nthOccurrence(event, "-", 4)+1, event.size() - nthOccurrence(event, "-", 4)) << std::endl;
		int totalValue = atoi(event.substr(nthOccurrence(event, "-", 2)+1, nthOccurrence(event, "-", 3) - nthOccurrence(event, "-", 2)-1).c_str());
		if(totalValue < 21)
		{
			std::string choice;
			std::cout << "You can now either hit or stand input [hit/stand]" << std::endl;
			bool cinFineFlag = true;
			while(cinFineFlag)
			{
				std::cin >> choice;
				if(choice == "hit")
				{
					sendIsHitting(HIT);
					cinFineFlag = false;
				}
				else if(choice == "stand")
				{
					sendIsHitting(STAND);
					cinFineFlag = false;
				}
				else
				{
					std::cout << "Wrong input try again:" << std::endl;
					cinFineFlag = false;
				}
			}
		}
	}

	void BlackJackPlayer::dealerFirstCard(std::string event)
	{
		std::cout << "The dealers first card is:" << std::endl;
		std::string card = event.substr(nthOccurrence(event, "-", 1)+1, nthOccurrence(event, "-", 2)-2);
		std::cout << card << std::endl;
		std::cout << "The total value the dealers card is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1) << std::endl;
	}

	void BlackJackPlayer::startHitting(std::string event)
	{
		int totalValue = atoi(event.substr(nthOccurrence(event, "-", 1)+1, event.size()-1).c_str());
		if(totalValue < 21)
		{
			std::string choice;
			std::cout << "You can now either hit or stand input [hit/stand]" << std::endl;
			bool cinFineFlag = true;
			while(cinFineFlag)
			{
				std::cin >> choice;
				if(choice == "hit")
				{
					sendIsHitting(HIT);
					cinFineFlag = false;
				}
				else if(choice == "stand")
				{
					sendIsHitting(STAND);
					cinFineFlag = false;
				}
				else
				{
					std::cout << "Wrong input try again:" << std::endl;
				}
			}
		}
		else if (totalValue == 21)
		{
			std::cout << "Your total value is 21, you will now stand." << std::endl;
			sendIsHitting(STAND);
		}
		else
		{
			std::cout << "Your total value has exceeded 21, your are busted, and can't proceed." << std::endl;
			sendIsHitting(STAND);
		}
	}

	void BlackJackPlayer::dealerNewCard(std::string event)
	{
		std::cout << "The dealer has chosen to hit and will now get a new card:" << std::endl;
		std::cout << "The dealers cards are:" << std::endl;
		std::string card = event.substr(nthOccurrence(event, "-", 1)+1, nthOccurrence(event, "-", 2)-2);
		std::cout << card << std::endl;
		std::cout << "The total value the dealers cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1) << std::endl;
	}

	void BlackJackPlayer::dealerSecondCard(std::string event)
	{
		std::cout << "All players has received their cards, and made their decisions. The dealer will now reveal their second card." << std::endl;
		std::cout << "The dealers cards are:" << std::endl;
		std::string card = event.substr(nthOccurrence(event, "-", 1)+1, nthOccurrence(event, "-", 2)-2);
		std::cout << card << std::endl;
		std::cout << "The total value the dealers cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1) << std::endl;

	}

	void BlackJackPlayer::dealerStand(std::string event)
	{
		std::cout << "The dealer stands." << std::endl;
	}

	void BlackJackPlayer::lost(std::string event)
	{
		std::cout << "You have lost." << std::endl;
		std::cout << "Your new balance is: " << event.substr(nthOccurrence(event, "-", 1)+1, event.size()-1) << std::endl;
		betting();
	}



	void BlackJackPlayer::newCard(std::string event)
	{
		std::cout << "You have chosen to receive a new card." << std::endl;
		std::cout << "Your cards are:" << std::endl;
		std::string cards = event.substr(nthOccurrence(event, "-", 1)+1, nthOccurrence(event, "-", 2)-2);
		std::cout << cards << std::endl;
		std::cout << "The total value of your cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1) << std::endl;
		int totalValue = atoi(event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1).c_str());
		if(totalValue < 21)
		{
			std::string choice;
			std::cout << "You can now either hit or stand input [hit/stand]" << std::endl;
			bool cinFineFlag = true;
			while(cinFineFlag)
			{
				std::cin >> choice;
				if(choice == "hit")
				{
					sendIsHitting(HIT);
					cinFineFlag = false;
				}
				else if(choice == "stand")
				{
					sendIsHitting(STAND);
					cinFineFlag = false;
				}
				else
				{
					std::cout << "Wrong input try again:" << std::endl;
					cinFineFlag = false;
				}
			}
		}
		else if (totalValue == 21)
		{
			std::cout << "Your total value is 21, you will now stand." << std::endl;
			sendIsHitting(STAND);
		}
		else
		{
			std::cout << "Your total value has exceeded 21, your are busted, and can't proceed." << std::endl;
			sendIsHitting(STAND);
		}
	}

	void BlackJackPlayer::won(std::string event)
	{
		std::cout << "You have won. Huraaaay!!" << std::endl;
		std::cout << "Your new balance is: " << event.substr(nthOccurrence(event, "-", 1)+1, event.size()-1) << std::endl;
		betting();
	}

	void BlackJackPlayer::betting()
	{
		int bet = 0;
		std:: cout << "A new game will start, you can now place your bets:" << std::endl;
		while(!(std::cin >> bet))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Value was not a number, try again." << std::endl;
		}
		sendBet(bet);

	}

	void BlackJackPlayer::sendBet(int money)
	{
		std::string sendString = intToString((int)BET) + "-" + intToString(money);
		stream.send(sendString);
	}

	void BlackJackPlayer::sendIsHitting(clientEvents event)
	{
		std::string sendString = intToString((int)event);
		stream.send(sendString);
	}



