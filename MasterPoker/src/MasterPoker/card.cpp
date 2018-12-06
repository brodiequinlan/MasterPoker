#include "mppch.h"


card::card(cardRank _rank, cardSuits _suit) : rank(_rank), suit(_suit) {};

card::card(cardRank _rank) :rank(_rank) {};
bool operator==(const card & lhs, const card & rhs)
{
	return (lhs.rank == rhs.rank && lhs.suit == rhs.suit); 
}
bool operator !=(const card& c, const card& b)
{
	if (c.rank == b.rank && c.suit == b.suit) return false;
	return true;
}