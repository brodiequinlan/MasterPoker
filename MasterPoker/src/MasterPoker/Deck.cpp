#include "Deck.hpp"
#include <algorithm>
#include <random>
Deck::Deck()
{
	fill();
	
}
void Deck::fill()
{
	unsigned suit = 0;
	for (int i = 0; i < 52; ++i)
	{
		if (i % 13 == 0 && i != 0)suit++;
		Deck::cards.push_back(std::make_shared<card>((cardRank)((i % 13) + 2), (cardSuits)suit));
	}
}
void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(Deck::cards.begin(), Deck::cards.end(), g);
}
const Deck::deck_type& Deck::getCards()
{
	return cards;
}
card Deck::draw()
{
	card x = *Deck::cards[0];
	Deck::removeCard(*Deck::cards[0]);
	return x;
}
bool Deck::removeCard(card x)
{
	if (Deck::getCards().size() < 1) return false;
	unsigned size = Deck::cards.size();
	Deck::cards.erase(std::remove_if(Deck::cards.begin(),Deck::cards.end(),[x](std::shared_ptr<card> c) {return *c == x; }),Deck::cards.end());
	return !(size == Deck::cards.size());
}

Deck::~Deck(){}

