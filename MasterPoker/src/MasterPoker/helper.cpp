#include <vector>

#include <iostream>
#include "helper.hpp"

#include <algorithm>
bool contains(const hand & v, const card & c1)
{
	for (const card c2 : v)
	{
		if (c2 == c1) return true;
	}
	return false;
}
bool containsRank(const hand & v, cardRank r)
{
	for (const card c2 : v)
	{
		if (c2.rank == r) return true;
	}
	return false;
}
void printHand(hand _hand)
{
	for (const card c :_hand)
	{
		std::cout << c.rank << std::endl;
	}
}
void printDeck(Deck::deck_type _hand)
{
	for (const std::shared_ptr<card> c : _hand)
	{
		std::cout << c->rank << "   " << c->suit << std::endl;
	}
}
void printHandPtr(hand_ptr _hand)
{
	for (const card c : _hand->hand_)
	{
		std::cout << c.rank << std::endl;
	}
}
bool operator !=(const card& c, const card& b)
{
	if (c.rank == b.rank && c.suit == b.suit) return false;
	return true;
}
bool operator ==(hand a,hand b)
{
	if (a.size() != b.size()) return false;
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool
	{
		if (lhs.rank < rhs.rank) return false;
		if (lhs.rank > rhs.rank) return true;
		if (lhs.suit < rhs.suit) return false;
		if (lhs.suit > rhs.suit) return true;
		return false;
	};
	std::sort(a.begin(), a.end(), cmpCardsRank);
	std::sort(b.begin(), b.end(), cmpCardsRank);
	for (unsigned i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			std::cout << a[i].rank << std::endl;
			std::cout << b[i].rank << std::endl;
			std::cout << a[i].suit << std::endl;
			std::cout << b[i].suit << std::endl;
			return false;
		}
	}
	return true;
}