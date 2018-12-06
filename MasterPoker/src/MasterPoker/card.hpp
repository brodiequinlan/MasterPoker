#pragma once

enum cardRank
{
	invalid, two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};
enum cardSuits
{
	clubs, spades, diamonds, hearts
};
struct card
{
	card(cardRank _rank, cardSuits _suit);
	card();
	card(cardRank _rank);
	cardRank rank;
	cardSuits suit;	

};
bool operator==(const card & lhs, const card & rhs);


