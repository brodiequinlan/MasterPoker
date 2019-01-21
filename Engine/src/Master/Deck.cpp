#include <Master/Deck.hpp>
#include <time.h>
#include <algorithm>
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
		Deck::cards.push_back(Card((Rank)((i % 13) + 2), (Suit)suit));
	}
}
void Deck::shuffle()
{
	std::random_shuffle(Deck::cards.begin(), Deck::cards.end());
}
const std::vector<Card>& Deck::getCards()
{
	return cards;
}
Card& Deck::draw()
{
	Card x = Deck::cards[0];
	Deck::removeCard(Deck::cards[0]);
	return x;
}
bool Deck::removeCardF(Card x)
{
	if (Deck::getCards().size() < 1) return false;
	size_t size = Deck::cards.size();
	Deck::cards.erase(std::remove_if(Deck::cards.begin(), Deck::cards.end(), [x](Card c) {return c == x; }), Deck::cards.end());
	return !(size == Deck::cards.size());
}
bool Deck::removeCard(Card x)
{
	if (Deck::getCards().size() < 1) return false;
	size_t size = Deck::cards.size();
	Deck::cards.erase(std::remove_if(Deck::cards.begin(), Deck::cards.end(), [x](Card c) {return c == x; }), Deck::cards.end());
	if (size != Deck::cards.size())
	{
		Deck::discards.push_back(Card(x));
	}
	return !(size == Deck::cards.size());
}
void Deck::reset()
{
	for (Card c : Deck::discards)
	{
		Deck::cards.push_back(c);
	}
	Deck::discards.clear();
}
Deck::~Deck() {}

