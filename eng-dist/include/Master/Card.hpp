#pragma once
#include <iostream>
enum Rank
{
	invalid, two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};
enum Suit
{
	clubs, spades, diamonds, hearts
};
class Card
{
	Rank rank_m;
	Suit suit_m;
public:
	Card(Rank,Suit);
	bool operator >(Card);
	bool operator <(Card);
	bool operator ==(Card);
	bool operator >=(Card);
	bool operator !=(Card);
	bool operator <=(Card);
	friend std::ostream& operator<<(std::ostream& cout, Card&);
	Suit getSuit();
	Rank getRank();
};
std::ostream& operator<<(std::ostream& cout, Card&);