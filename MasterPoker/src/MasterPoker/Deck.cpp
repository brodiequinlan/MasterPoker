#include "Deck.hpp"
#include <algorithm>
#include <random>
#include <ctime>  
Deck::Deck()
{
	fill();
	std::srand(unsigned(std::time(0)));
}
void Deck::fill()
{
	unsigned suit = 0;
	for (int i = 0; i < 52; ++i)
	{
		if (i % 13 == 0 && i != 0)suit++;
		Deck::cards.push_back(card((cardRank)((i % 13) + 2), (cardSuits)suit));
	}
}
void Deck::shuffle()
{
	std::random_shuffle(Deck::cards.begin(), Deck::cards.end());
}
const Deck::deck_type& Deck::getCards()
{
	return cards;
}
card Deck::draw()
{
	card x = Deck::cards[0];
	Deck::removeCard(Deck::cards[0]);
	return x;
}
bool Deck::removeCardF(card x)
{
	if (Deck::getCards().size() < 1) return false;
	unsigned size = Deck::cards.size();
	Deck::cards.erase(std::remove_if(Deck::cards.begin(), Deck::cards.end(), [x](card c) {return c == x; }), Deck::cards.end());
	return !(size == Deck::cards.size());
}
bool Deck::removeCard(card x)
{
	if (Deck::getCards().size() < 1) return false;
	unsigned size = Deck::cards.size();
	Deck::cards.erase(std::remove_if(Deck::cards.begin(),Deck::cards.end(),[x](card c) {return c == x; }),Deck::cards.end());
	if (size != Deck::cards.size())
	{
		Deck::discards.push_back(card(x));
	}
	return !(size == Deck::cards.size());
}
void Deck::reset()
{
	for (card c : Deck::discards)
	{
		Deck::cards.push_back(c);
	}
	Deck::discards.clear();
}
Deck::~Deck(){}

