#include "card.hpp"
card::card(cardRank _rank, cardSuits _suit) :rank(_rank), suit(_suit) {};
card::card() = default;
card::card(cardRank _rank) :rank(_rank) {};
bool operator==(const card & lhs, const card & rhs)
{
	return (lhs.rank == rhs.rank && lhs.suit == rhs.suit);
}