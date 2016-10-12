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

	}

	void BlackJackPlayer::handleEvent(handle handle, EventHandle::Reactor::EventType et)
	{
		std::cout << "from bj handler" << std::endl;
		if(et == EventHandle::Reactor::READ_EVENT)
		{
			std::string msg = "";
			if(stream.receive(msg) == OSAL::INET::SocketStream::SOCKETOK)
			{
				std::cout << msg << std::endl;
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
			break;
		case GameLogic::Player::DEALERFIRSTCARD:
			break;
		case GameLogic::Player::DEALERNEWCARD:
			break;
		case GameLogic::Player::DEALERSECONDCARD:
			break;
		case GameLogic::Player::DEALERSTAND:
			break;
		case GameLogic::Player::LOST:
			break;
		case GameLogic::Player::NEWCARD:
			break;
		case GameLogic::Player::WON:
			break;

		}
	}

	std::string BlackJackPlayer::intToString(int value)
	{

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
		std::cout << "All players has placed their bets, and the dealer will now proceed to deal cards" << std::endl;
		std::cout << "Your cards are:" << std::endl;
		std::string cards = event.substr(nthOccurrence(event, "-", 1), nthOccurrence(event, "-", 2));
		std::cout << cards << std::endl;
		std::cout << "The total value of your cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1);
		std::cout << "Your cards are:" << std::endl;
		std::string cards = event.substr(nthOccurrence(event, "-", 1), nthOccurrence(event, "-", 2));
		std::cout << cards << std::endl;
		std::cout << "The total value of your cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1);
		int totalValue = atoi(event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1).c_str());
		if(totalValue > 21)
		{
			std::string choice;
			std::cout << "You can now either hit or stand input [hit/stand]" << std::endl;
			bool cinFineFlag = true;
			while(cinFineFlag)
			{
				std::cin >> choice;
				if(choice == "hit")
				{

				}
				else if(choice == "stand")
				{

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
		}
		else
		{
			std::cout << "Your total value has exceeded 21, your are busted, and can't proceed." << std::endl;
		}

	}

	void BlackJackPlayer::dealerFirstCard(std::string event)
	{
		std::cout << "The dealers first card is:" << std::endl;
		std::string card = event.substr(nthOccurrence(event, "-", 1), nthOccurrence(event, "-", 2));
		std::cout << card << std::endl;
		std::cout << "The total value the dealers card is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1);
	}

	void BlackJackPlayer::dealerNewCard(std::string event)
	{
		std::cout << "The dealer has chosen to hit and will now get a new card:" << std::endl;
		std::cout << "The dealers cards are:" << std::endl;
		std::string card = event.substr(nthOccurrence(event, "-", 1), nthOccurrence(event, "-", 2));
		std::cout << card << std::endl;
		std::cout << "The total value the dealers cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1);
	}

	void BlackJackPlayer::dealerSecondCard(std::string event)
	{
		std::cout << "All players has received their cards, and made their decisions. The dealer will now reveal their second card." << std::endl;
		std::cout << "The dealers cards are:" << std::endl;
		std::string card = event.substr(nthOccurrence(event, "-", 1), nthOccurrence(event, "-", 2));
		std::cout << card << std::endl;
		std::cout << "The total value the dealers cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1);

	}

	void BlackJackPlayer::dealerStand(std::string event)
	{
		std::cout << "The dealer stands." << std::endl;
	}

	void BlackJackPlayer::lost(std::string event)
	{
		std::cout << "You have lost." << std::endl;
		std::cout << "Your new balance is:" << event.substr(nthOccurrence(event, "-", 1)+1, event.size()-1) << std::endl;
		betting();
	}



	void BlackJackPlayer::newCard(std::string event)
	{
		std::cout << "Your cards are:" << std::endl;
		std::string cards = event.substr(nthOccurrence(event, "-", 1), nthOccurrence(event, "-", 2));
		std::cout << cards << std::endl;
		std::cout << "The total value of your cards is: " << event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1);
		int totalValue = atoi(event.substr(nthOccurrence(event, "-", 2)+1, event.size()-1).c_str());
		if(totalValue > 21)
		{
			std::string choice;
			std::cout << "You can now either hit or stand input [hit/stand]" << std::endl;
			bool cinFineFlag = true;
			while(cinFineFlag)
			{
				std::cin >> choice;
				if(choice == "hit")
				{

				}
				else if(choice == "stand")
				{

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
		}
		else
		{
			std::cout << "Your total value has exceeded 21, your are busted, and can't proceed." << std::endl;
		}
	}

	void BlackJackPlayer::won(std::string event)
	{
		std::cout << "You have won. Huraaaay!!" << std::endl;
		std::cout << "Your new balance is:" << event.substr(nthOccurrence(event, "-", 1)+1, event.size()-1) << std::endl;
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

	}



