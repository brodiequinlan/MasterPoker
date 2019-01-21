#include <Master/Card.hpp>

Card::Card(Rank rank, Suit suit):rank_m(rank),suit_m(suit) {}

bool Card::operator<(Card other)
{
	return rank_m < other.rank_m;
}
bool Card::operator>(Card other)
{
	return rank_m > other.rank_m;
}
bool Card::operator==(Card other)
{
	return (rank_m == other.rank_m && suit_m == other.suit_m);
}
bool Card::operator<=(Card other)
{
	return rank_m <= other.rank_m;
}
bool Card::operator>=(Card other)
{
	return rank_m >= other.rank_m;
}
bool Card::operator!=(Card other)
{
	return !(rank_m == other.rank_m && suit_m == other.suit_m);
}
std::ostream& operator<<(std::ostream& cout, Card& card)
{
	cout << card.rank_m << " : " << card.suit_m << std::endl;
	return cout;
}
Suit Card::getSuit()
{
	return suit_m;
}
Rank Card::getRank()
{
	return rank_m;
}