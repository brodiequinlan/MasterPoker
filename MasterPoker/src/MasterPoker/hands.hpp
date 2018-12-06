#pragma once

using hand_vector = std::vector<card>;
struct  baseHand
{
	std::string name;
	unsigned ranking;
	std::vector<card> hand_;
	bool is;
	bool operator > (const baseHand& b);
};
struct RoyalFlush : public baseHand
{
	RoyalFlush()
	{
		name = "Royal";
		ranking = 0;
	}
	
};

struct  StraightFlush : public baseHand
{
	StraightFlush(const hand_vector & _hand, bool _is);
	operator bool();
};

struct  fullHouse : public baseHand
{
	fullHouse(cardRank _x, cardRank _fullOf, bool _is);
	cardRank x;
	cardRank fullOf;
	operator bool();
};
struct  quads : public baseHand
{
	quads(cardRank _fourOf, cardRank _highCard, bool _is); 
	cardRank fourOf;
	cardRank highCard;
	operator bool();
};
struct  highCard : public baseHand
{
	highCard(const hand_vector & _hand);
};
struct  flush : public baseHand
{
	flush(const hand_vector & _hand,bool _is);
	operator bool();
};
struct  Straight : public baseHand
{
	Straight(const hand_vector & _hand, bool _is);
	operator bool();
};
struct  Trips : public baseHand
{
	Trips(const hand_vector & _hand, bool _is);
	operator bool();
};
struct  TwoPair : baseHand
{
	TwoPair(const hand_vector & _hand, bool is);
	operator bool();
};
struct  singlePair : baseHand
{
	singlePair(const hand_vector & _hand, bool is);
	operator bool();
};