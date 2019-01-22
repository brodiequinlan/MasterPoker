#pragma once

#include <vector>
#include <Master/Card.hpp>
#include <memory>
using hand_vector = std::vector<Card>;

struct Hand
{
	std::string name;
	unsigned ranking;
	std::vector<Card> hand_;
	bool is;
	bool operator > (const Hand& b);
};
struct RoyalFlush : public Hand
{
	RoyalFlush()
	{
		name = "Royal";
		ranking = 0;
	}

};

struct  StraightFlush : public Hand
{
	StraightFlush(const hand_vector & _hand, bool _is);
	operator bool();
};

struct  fullHouse : public Hand
{
	fullHouse(Rank _x, Rank _fullOf, bool _is);
	Rank x;
	Rank fullOf;
	operator bool();
};
struct  quads : public Hand
{
	quads(Rank _fourOf, Rank _highCard, bool _is);
	Rank fourOf;
	Rank highCard;
	operator bool();
};
struct  highCard : public Hand
{
	highCard(const hand_vector & _hand);
};
struct  flush : public Hand
{
	flush(const hand_vector & _hand, bool _is);
	operator bool();
};
struct  Straight : public Hand
{
	Straight(const hand_vector & _hand, bool _is);
	operator bool();
};
struct  Trips : public Hand
{
	Trips(const hand_vector & _hand, bool _is);
	operator bool();
};
struct  TwoPair : Hand
{
	TwoPair(const hand_vector & _hand, bool is);
	operator bool();
};
struct  singlePair : Hand
{
	singlePair(const hand_vector & _hand, bool is);
	operator bool();
};

using hand_ptr = std::unique_ptr<Hand>;
StraightFlush isStraightFlush(const hand_vector & hand);
bool isRoyalFlush(const hand_vector & hand);
quads isQuads(const hand_vector & hand);
fullHouse isFullHouse(const hand_vector & hand);
flush isFlush(const hand_vector & hand);
Straight isStraight(const hand_vector & hand);
Trips isTrips(const hand_vector & hand);
TwoPair isTwoPair(const hand_vector & hand);
singlePair isPair(const hand_vector & hand);
highCard getHighCard(const hand_vector & hand);


bool operator ==(hand_vector a, hand_vector b);
bool contains(const hand_vector & v, const Card & c1);
bool containsRank(const hand_vector& v, Rank r);

std::ostream& operator<<(std::ostream& out, const hand_vector & h);
std::ostream& operator<<(std::ostream& out, const hand_ptr & h);