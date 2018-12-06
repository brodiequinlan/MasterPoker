#include "mppch.h"
#include "hands.hpp"
StraightFlush::StraightFlush(const hand_vector& _hand, bool _is)
{
	hand_ = _hand;
	is = _is;
	ranking = 1;
	name = "straight flush";
};
StraightFlush::operator bool()
{
	return is;
}

fullHouse::fullHouse(cardRank _x, cardRank _fullOf, bool _is) :x(_x), fullOf(_fullOf)
{
	is = _is;
	ranking = 3;
	name = "full house";
	hand_.push_back(card(_x));
	hand_.push_back(card(_x));
	hand_.push_back(card(_x));
	hand_.push_back(card(_fullOf));
	hand_.push_back(card(_fullOf));
};
fullHouse::operator bool()
{
	return is;
}

highCard::highCard(const hand_vector & _hand)
{
	hand_ = _hand;
	ranking = 9;
	name = "high card";
};


quads::quads(cardRank _fourOf, cardRank _highCard, bool _is) :fourOf(_fourOf),highCard(_highCard)
{
	is = _is;
	ranking = 2;
	name = "quads";
	hand_.push_back(card(_fourOf));
	hand_.push_back(card(_fourOf));
	hand_.push_back(card(_fourOf));
	hand_.push_back(card(_fourOf));
	hand_.push_back(card(_highCard));
};
quads::operator bool()
{
	return is;
}
flush::flush(const hand_vector & _hand, bool _is)
{
	hand_ = _hand;
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool
	{
		if (lhs.rank < rhs.rank) return false;
		if (lhs.rank > rhs.rank) return true;
		if (lhs.suit < rhs.suit) return false;
		if (lhs.suit > rhs.suit) return true;
		return false;
	};
	std::sort(hand_.begin(), hand_.end(), cmpCardsRank);
	is = _is;
	ranking = 4;
	name = "flush";
};
flush::operator bool()
{
	return is;
}
Straight::Straight(const hand_vector & _hand, bool _is)
{
	hand_ = _hand;
	is = _is;
	ranking = 5;
	name = "straight";
};
Straight::operator bool()
{
	return is;
}

Trips::Trips(const hand_vector & _hand, bool _is)
{
	hand_ = _hand;
	is = _is;
	ranking = 6;
	name = "3 of a kind";
};
Trips::operator bool()
{
	return is;
}
TwoPair::TwoPair(const hand_vector & _hand, bool _is)
{
	hand_ = _hand;
	is = _is;
	ranking = 7;
	name = "two pair";
}
TwoPair::operator bool()
{
	return is;
}
singlePair::singlePair(const hand_vector & _hand, bool _is)
{
	hand_ = _hand;
	is = _is;
	ranking = 8;
	name = "pair";
}
singlePair::operator bool()
{
	return is;
}

bool baseHand::operator>(const baseHand& b)
{
	if (ranking > b.ranking) return false;
	else if (ranking < b.ranking) return true;

	if (ranking == 0)
	{
		if(b.ranking == 0)
		return false;

		return true;
	}
	else if (ranking == 1)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		for (int i = 0; i < hand_.size(); ++i)
		{
			if (hand_[i].rank > b.hand_[i].rank) return true;
			else if (hand_[i].rank < b.hand_[i].rank) return false;
		}
		return false;
	}
	else if (ranking == 2)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0].rank > b.hand_[0].rank)return true;
		else if (hand_[0].rank < b.hand_[0].rank)return false;
		else
		{
			if (hand_[4].rank > b.hand_[4].rank)return true;
			else if (hand_[4].rank < b.hand_[4].rank)return false;
		}
		return false;
	}
	else if (ranking == 3)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0].rank > b.hand_[0].rank)return true;
		else if (hand_[0].rank < b.hand_[0].rank)return false;
		else
		{
			if (hand_[4].rank > b.hand_[4].rank)return true;
			else if (hand_[4].rank < b.hand_[4].rank)return false;
		}
		return false;
	}
	else if (ranking == 4)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		for (int i = 0; i < hand_.size(); ++i)
		{
			if (hand_[i].rank > b.hand_[i].rank) return true;
			else if (hand_[i].rank < b.hand_[i].rank) return false;
		}
		return false;
	}
	else if (ranking == 5)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		for (int i = 0; i < hand_.size(); ++i)
		{
			if (hand_[i].rank > b.hand_[i].rank) return true;
			else if (hand_[i].rank < b.hand_[i].rank) return false;
		}
		return false;
	}
	else if (ranking == 6)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0].rank > b.hand_[0].rank)return true;
		else if (hand_[0].rank < b.hand_[0].rank)return false;

		if (hand_[3].rank > b.hand_[3].rank)return true;
		else if (hand_[3].rank < b.hand_[3].rank)return false;
		
		if (hand_[4].rank > b.hand_[4].rank)return true;
		else if (hand_[4].rank < b.hand_[4].rank)return false;
		return false;
	}
	else if (ranking == 7)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0].rank > b.hand_[0].rank && hand_[0].rank > b.hand_[2].rank)
		{
			return true;
		}
		else if (hand_[0].rank == b.hand_[0].rank && hand_[0].rank > b.hand_[2].rank)
		{
			return true;
		}
		else if (hand_[2].rank > b.hand_[0].rank && hand_[0].rank == b.hand_[2].rank)
		{
			return true;
		}
		else if (hand_[2].rank == b.hand_[0].rank && hand_[0].rank == b.hand_[2].rank)
		{
			if (hand_[4].rank > b.hand_[4].rank) return true;
		}
		return false;
	}
	else if (ranking == 8)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0].rank > b.hand_[0].rank)
		{
			return true;
		}
		else if (hand_[0].rank < b.hand_[0].rank)
		{
			return false;
		}
		else if (hand_[0].rank == b.hand_[0].rank)
		{
			if (hand_[2].rank > b.hand_[2].rank) return true;
			else if (hand_[3].rank > b.hand_[3].rank) return true;
			else if (hand_[4].rank > b.hand_[4].rank) return true;
		}
	}
	else if (ranking == 9)
	{
		if (hand_[0].rank > b.hand_[0].rank) return true;
		else if (hand_[1].rank > b.hand_[1].rank) return true;
		else if (hand_[2].rank > b.hand_[2].rank) return true;
		else if (hand_[3].rank > b.hand_[3].rank) return true;
		else if (hand_[4].rank > b.hand_[4].rank) return true;
	}
	return false;
}
