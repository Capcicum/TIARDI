/*
 * Deck.cpp
 *
 *  Created on: 11. okt. 2016
 *      Author: Andersen
 */


#include <GameLogic/Deck.hpp>

namespace GameLogic {


	Deck::Deck(int numOfDecks)
	{
		createNewDeck(numOfDecks);
		shuffleDeck();
	}

	void Deck::clear()
	{
		deck.clear();
	}

	void Deck::createNewDeck(int numOfDecks)
	{
		for(int i = 0; i <= numOfDecks; i++)
		{
			for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
			{
				for (int r = Card::ACE; r <= Card::KING; ++r)
				{
					Card* card = new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s));
					deck.push_back(card);
				}
			}
		}
	}

	void Deck::shuffleDeck()
	{
		std::random_shuffle(deck.begin(), deck.end());
	}

	Card* Deck::getCard()
	{
		Card* card = deck.back();
		deck.pop_back();
		return card;
	}

	int Deck::getCardsLeft()
	{
		return deck.size();
	}


}

