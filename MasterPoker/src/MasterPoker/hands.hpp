#pragma once

#include <vector>
#include "card.hpp"
using hand = std::vector<card>;
struct MASTER_API baseHand
{
	std::string name;
	unsigned ranking;
	std::vector<card> hand_;
	bool is;
	bool operator > (baseHand b);
};
struct MASTER_API RoyalFlush : public baseHand
{
	RoyalFlush()
	{
		name = "Royal";
		ranking = 0;
	}
	
};

struct MASTER_API StraightFlush : public baseHand
{
	StraightFlush(const hand & _hand, bool _is);
	operator bool();
};

struct MASTER_API fullHouse : public baseHand
{
	fullHouse(cardRank _x, cardRank _fullOf, bool _is);
	cardRank x;
	cardRank fullOf;
	operator bool();
};
struct MASTER_API quads : public baseHand
{
	quads(cardRank _fourOf, cardRank _highCard, bool _is); 
	cardRank fourOf;
	cardRank highCard;
	operator bool();
};
struct MASTER_API highCard : public baseHand
{
	highCard(const hand & _hand);
};
struct MASTER_API flush : public baseHand
{
	flush(const hand & _hand,bool _is);
	operator bool();
};
struct MASTER_API Straight : public baseHand
{
	Straight(const hand & _hand, bool _is);
	operator bool();
};
struct MASTER_API Trips : public baseHand
{
	Trips(const hand & _hand, bool _is);
	operator bool();
};
struct MASTER_API TwoPair : baseHand
{
	TwoPair(const hand & _hand, bool is);
	operator bool();
};
struct MASTER_API singlePair : baseHand
{
	singlePair(const hand & _hand, bool is);
	operator bool();
};