#pragma once
#include "enums.hpp"
#include "Core.h"
struct MASTER_API card
{
	card(cardRank _rank, cardSuits _suit);
	card();
	card(cardRank _rank);
	cardRank rank;
	cardSuits suit;

};
MASTER_API bool operator==(const card & lhs, const card & rhs);


