#include "mppch.h"


bool contains(const hand_vector & v, const card & c1)
{
	for (const card c2 : v)
	{
		if (c2 == c1) return true;
	}
	return false;
}
bool containsRank(const hand_vector & v, cardRank r)
{
	for (const card c2 : v)
	{
		if (c2.rank == r) return true;
	}
	return false;
}
void printHand(const hand_vector& _hand)
{
	for (const card c :_hand)
	{
		std::cout << c.rank << std::endl;
	}
}
void printDeck(const Deck::deck_type& _hand)
{
	for (const card c : _hand)
	{
		std::cout << c.rank << "   " << c.suit << std::endl;
	}
}
void printHandPtr(const hand& _hand)
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
bool operator ==(hand_vector a,hand_vector b)
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
			return false;
		}
	}
	return true;
}
