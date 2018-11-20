#include "Deck.hpp"


Deck::Deck()
{
	unsigned suit = 0;
	for (int i = 0; i < 52; ++i)
	{
		if (i % 13 == 0 && i!=0)suit++;
		Deck::cards.push_back(std::make_shared<card>((cardRank)((i%13) + 2),(cardSuits)suit));
	}
}

const Deck::deck_type& Deck::getCards()
{
	return cards;
}


Deck::~Deck()
{
}

