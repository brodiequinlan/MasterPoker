#include "Master/Card.hpp"
#include "Master/Hand.hpp"
#include <algorithm>
#include <map>
#include <iostream>
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

fullHouse::fullHouse(Rank _x, Rank _fullOf, bool _is) :x(_x), fullOf(_fullOf)
{
	is = _is;
	ranking = 3;
	name = "full house";
	hand_.push_back(Card(_x,clubs));
	hand_.push_back(Card(_x, clubs));
	hand_.push_back(Card(_x, clubs));
	hand_.push_back(Card(_fullOf, clubs));
	hand_.push_back(Card(_fullOf, clubs));
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


quads::quads(Rank _fourOf, Rank _highCard, bool _is) :fourOf(_fourOf), highCard(_highCard)
{
	is = _is;
	ranking = 2;
	name = "quads";
	hand_.push_back(Card(_fourOf,clubs));
	hand_.push_back(Card(_fourOf,clubs));
	hand_.push_back(Card(_fourOf,clubs));
	hand_.push_back(Card(_fourOf,clubs));
	hand_.push_back(Card(_highCard,clubs));
};
quads::operator bool()
{
	return is;
}
flush::flush(const hand_vector & _hand, bool _is)
{
	hand_ = _hand;
	auto cmpCardsRank = [](Card & lhs, Card & rhs) -> bool
	{
		if (lhs < rhs) return false;
		if (lhs > rhs) return true;
		if (lhs < rhs) return false;
		if (lhs > rhs) return true;
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

bool Hand::operator>(const Hand& b)
{
	if (ranking > b.ranking) return false;
	else if (ranking < b.ranking) return true;

	if (ranking == 0)
	{
		if (b.ranking == 0)
			return false;

		return true;
	}
	else if (ranking == 1)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		for (int i = 0; i < hand_.size(); ++i)
		{
			if (hand_[i] > b.hand_[i]) return true;
			else if (hand_[i] < b.hand_[i]) return false;
		}
		return false;
	}
	else if (ranking == 2)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0]> b.hand_[0])return true;
		else if (hand_[0] < b.hand_[0])return false;
		else
		{
			if (hand_[4] > b.hand_[4])return true;
			else if (hand_[4] < b.hand_[4])return false;
		}
		return false;
	}
	else if (ranking == 3)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0] > b.hand_[0])return true;
		else if (hand_[0] < b.hand_[0])return false;
		else
		{
			if (hand_[4] > b.hand_[4])return true;
			else if (hand_[4] < b.hand_[4])return false;
		}
		return false;
	}
	else if (ranking == 4)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		for (int i = 0; i < hand_.size(); ++i)
		{
			if (hand_[i] > b.hand_[i]) return true;
			else if (hand_[i] < b.hand_[i]) return false;
		}
		return false;
	}
	else if (ranking == 5)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		for (int i = 0; i < hand_.size(); ++i)
		{
			if (hand_[i] > b.hand_[i]) return true;
			else if (hand_[i] < b.hand_[i]) return false;
		}
		return false;
	}
	else if (ranking == 6)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0] > b.hand_[0])return true;
		else if (hand_[0] < b.hand_[0])return false;

		if (hand_[3] > b.hand_[3])return true;
		else if (hand_[3] < b.hand_[3])return false;

		if (hand_[4] > b.hand_[4])return true;
		else if (hand_[4] < b.hand_[4])return false;
		return false;
	}
	else if (ranking == 7)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0] > b.hand_[0] && hand_[0] > b.hand_[2])
		{
			return true;
		}
		else if (hand_[0] == b.hand_[0] && hand_[0] > b.hand_[2])
		{
			return true;
		}
		else if (hand_[2] > b.hand_[0] && hand_[0] == b.hand_[2])
		{
			return true;
		}
		else if (hand_[2] == b.hand_[0] && hand_[0] == b.hand_[2])
		{
			if (hand_[4] > b.hand_[4]) return true;
		}
		return false;
	}
	else if (ranking == 8)
	{
		//NOT EXCEPTION SAFE YET FIX LATER (eg throw ex if a.size != b.size but for now well assume input is correct
		if (hand_[0] > b.hand_[0])
		{
			return true;
		}
		else if (hand_[0] < b.hand_[0])
		{
			return false;
		}
		else if (hand_[0] == b.hand_[0])
		{
			if (hand_[2] > b.hand_[2]) return true;
			else if (hand_[3] > b.hand_[3]) return true;
			else if (hand_[4] > b.hand_[4]) return true;
		}
	}
	else if (ranking == 9)
	{
		if (hand_[0] > b.hand_[0]) return true;
		else if (hand_[1] > b.hand_[1]) return true;
		else if (hand_[2] > b.hand_[2]) return true;
		else if (hand_[3] > b.hand_[3]) return true;
		else if (hand_[4] > b.hand_[4]) return true;
	}
	return false;
}
bool isRoyalFlush(const hand_vector & _hand)
{
	Card a(ace, spades);
	Card k(king, spades);
	Card q(queen, spades);
	Card j(jack, spades);
	Card t(ten, spades);

	if (contains(_hand, a) && contains(_hand, k) && contains(_hand, q) && contains(_hand, j) && contains(_hand, t)) return true;

	a = Card(ace, clubs);
	k = Card(king, clubs);
	q = Card(queen, clubs);
	j = Card(jack, clubs);
	t = Card(ten, clubs);

	if (contains(_hand, a) && contains(_hand, k) && contains(_hand, q) && contains(_hand, j) && contains(_hand, t)) return true;

	a = Card(ace,  diamonds);
	k = Card(king, diamonds);
	q = Card(queen,diamonds);
	j = Card(jack, diamonds);
	t = Card(ten,  diamonds);

	if (contains(_hand, a) && contains(_hand, k) && contains(_hand, q) && contains(_hand, j) && contains(_hand, t)) return true;


	a = Card(ace,   hearts);
	k = Card(king,  hearts);
	q = Card(queen, hearts);
	j = Card(jack,  hearts);
	t = Card(ten,   hearts);

	if (contains(_hand, a) && contains(_hand, k) && contains(_hand, q) && contains(_hand, j) && contains(_hand, t)) return true;

	return false;
}

StraightFlush isStraightFlush(const hand_vector & _hand)
{
	hand_vector clubCards;
	hand_vector spadeCards;
	hand_vector diaCards;
	hand_vector hearCards;

	hand_vector copy (_hand.begin(), _hand.end());
	auto cmpCardsRank = [](Card & lhs, Card & rhs) -> bool {return lhs < rhs; };
	std::sort(copy.begin(), copy.end(), cmpCardsRank);

	for (Card c : copy)
	{
		switch (c.getSuit())
		{
			case clubs:clubCards.push_back(c); break;
			case spades: spadeCards.push_back(c); break;
			case diamonds: diaCards.push_back(c); break;
			case hearts: hearCards.push_back(c); break;
		}
	}
	if (!(clubCards.size() >= 5 || spadeCards.size() >= 5 || diaCards.size() >= 5 || hearCards.size() >= 5)) return StraightFlush(_hand, false);
	

	int count = 1;
	bool foundSf = false;
	hand_vector currentSf;
	hand_vector oldSf;
	size_t compareSize = spadeCards.size() + 1;
	if (spadeCards.size() >= 5)
	{
		Card z(ace, spades);
		if (spadeCards[0].getRank() == 2 && contains(spadeCards, z)) {
			spadeCards.erase(spadeCards.end() - 1);
			currentSf.push_back(Card(ace, spades));
			count++;
			//compareSize++;
		}
		for (int i = 0; i < spadeCards.size() - 1; ++i)
		{
			if (count >= 5) {
				if (spadeCards.size() == compareSize) {
					return (StraightFlush(currentSf, true));
				}
			}
			if (spadeCards[i + 1].getRank() - spadeCards[i].getRank() == 1 && spadeCards[i].getSuit() == spadeCards[i + 1].getSuit())
			{
				if (currentSf.size() == 5)
				{
					currentSf.erase(currentSf.begin());
				}
				if (i == 0)currentSf.push_back(spadeCards[0]);
				currentSf.push_back(spadeCards[i + 1]);
				count++;
			}
			else {
				count = 1;
				oldSf = currentSf;
				currentSf.clear();
			}
		}
	}
	else if (clubCards.size() >= 5)
	{
		Card z(ace, spades);
		if (clubCards[0].getRank() == 2 && contains(clubCards, z)) {
			clubCards.erase(clubCards.end() - 1);
			currentSf.push_back(Card(ace, clubs));
			count++;
			//compareSize++;
		}
		for (int i = 0; i < clubCards.size() - 1; ++i)
		{
			if (count >= 5) {
				if (clubCards.size() == compareSize) {
					return (StraightFlush(currentSf, true));
				}
			}
			if (clubCards[i + 1].getRank() - clubCards[i].getRank() == 1 && clubCards[i].getSuit() == clubCards[i + 1].getSuit())
			{
				if (currentSf.size() == 5)
				{
					currentSf.erase(currentSf.begin());
				}
				if (i == 0)currentSf.push_back(clubCards[0]);
				currentSf.push_back(clubCards[i + 1]);
				count++;
			}
			else {
				count = 1;
				oldSf = currentSf;
				currentSf.clear();
			}
		}
	}
	else if (diaCards.size() >= 5)
	{
		Card z(ace, spades);
		if (diaCards[0].getRank() == 2 && contains(diaCards, z)) {
			diaCards.erase(diaCards.end() - 1);
			currentSf.push_back(Card(ace, diamonds));
			count++;
			//compareSize++;
		}
		for (int i = 0; i < diaCards.size() - 1; ++i)
		{
			if (count >= 5) {
				if (diaCards.size() == compareSize) {
					return (StraightFlush(currentSf, true));
				}
			}
			if (diaCards[i + 1].getRank() - diaCards[i].getRank() == 1 && diaCards[i].getSuit() == diaCards[i + 1].getSuit())
			{
				if (currentSf.size() == 5)
				{
					currentSf.erase(currentSf.begin());
				}
				if (i == 0)currentSf.push_back(diaCards[0]);
				currentSf.push_back(diaCards[i + 1]);
				count++;
			}
			else {
				count = 1;
				oldSf = currentSf;
				currentSf.clear();
			}
		}
	}
	else if (hearCards.size() >= 5)
	{
		Card z(ace, spades);
		if (hearCards[0].getRank() == 2 && contains(hearCards, z)) {
			hearCards.erase(hearCards.end() - 1);
			currentSf.push_back(Card(ace, spades));
			count++;
			//compareSize++;
		}
		for (int i = 0; i < hearCards.size() - 1; ++i)
		{
			if (count >= 5) {
				if (hearCards.size() == compareSize) {
					return (StraightFlush(currentSf, true));
				}
			}
			if (hearCards[i + 1].getRank() - hearCards[i].getRank() == 1 && hearCards[i].getSuit() == hearCards[i + 1].getSuit())
			{
				if (currentSf.size() == 5)
				{
					currentSf.erase(currentSf.begin());
				}
				if (i == 0)currentSf.push_back(hearCards[0]);
				currentSf.push_back(hearCards[i + 1]);
				count++;
			}
			else {
				count = 1;
				oldSf = currentSf;
				currentSf.clear();
			}
		}
	}
	if (currentSf.size() == 5) return (StraightFlush(currentSf, true));
	else if (oldSf.size() == 5)return StraightFlush(oldSf, true);
	else return StraightFlush(_hand, false);
}

quads isQuads(const hand_vector & _hand)
{
	Rank quad = ace;
	Rank high = ace;
	bool foundFour = false;
	std::map<Rank, int> count;
	for (Card c : _hand)
	{
		count[c.getRank()]++;
	}
	for (std::map<Rank, int>::iterator it = count.begin(); it != count.end();)
	{
		if (it->second == 4)
		{
			quad = it->first;
			count.erase(it++);
			foundFour = true;
		}
		else
		{
			++it;
		}
	}
	if (foundFour)
	{
		auto x = count.end(); --x;
		high = x->first;
		return quads(quad, high, true);
	}
	else
	{
		return quads(quad, high, false);
	}
}

fullHouse isFullHouse(const hand_vector & _hand)
{
	std::map<Rank, int> count;
	bool twoCount = false, threeCount = false;
	bool multiThree = false;
	std::map<Rank, int>::iterator currentTwo;
	std::map<Rank, int>::iterator currentThree;
	std::map<Rank, int>::iterator secondThree;
	for (Card c : _hand)
	{
		count[c.getRank()]++;
	}
	for (std::map<Rank, int>::iterator it = count.begin(); it != count.end(); ++it)
	{
		if (it->second == 3) {
			if (threeCount)
			{
				multiThree = true;
				if (currentThree->first < it->first) {
					secondThree = currentThree;
					currentThree = it;
				}
				else {
					secondThree = it;
				}
				break;
			}
			else
			{
				currentThree = it;
			}
			threeCount = true;
		}
		else if (it->second == 2)
		{
			if (twoCount)
			{
				if (currentTwo->first < it->first)
				{
					currentTwo = it;
				}
			}
			else
			{
				currentTwo = it;
			}
			twoCount = true;
		}
	}
	if (multiThree)
	{
		return (fullHouse(currentThree->first, secondThree->first, true));
	}
	else if (twoCount && threeCount)
	{
		return (fullHouse(currentThree->first, currentTwo->first, true));
	}
	else
	{
		return (fullHouse(ace, ace, false));
	}
}

flush isFlush(const hand_vector & _hand)
{
	hand_vector clubCards;
	hand_vector spadeCards;
	hand_vector diaCards;
	hand_vector hearCards;

	for (Card c : _hand)
	{
		switch (c.getSuit())
		{
		case clubs:clubCards.push_back(c); break;
		case spades: spadeCards.push_back(c); break;
		case diamonds: diaCards.push_back(c); break;
		case hearts: hearCards.push_back(c); break;
		}
	}
	auto cmpCardsRank = []( Card & lhs,  Card & rhs) -> bool {return lhs.getRank() < rhs.getRank(); };
	if (!(clubCards.size() >= 5 || spadeCards.size() >= 5 || diaCards.size() >= 5 || hearCards.size() >= 5)) return flush(_hand, false);
	if (clubCards.size() == 5) return flush(clubCards, true);
	else if (clubCards.size() > 5)
	{
		hand_vector flu;
		std::sort(clubCards.begin(), clubCards.end(), cmpCardsRank);
		for (size_t i = clubCards.size() - 5; i < clubCards.size(); ++i)
		{
			flu.push_back(clubCards[i]);
		}
		return flush(flu, true);
	}
	if (spadeCards.size() == 5) return flush(spadeCards, true);
	else if (spadeCards.size() > 5)
	{
		hand_vector flu;
		std::sort(spadeCards.begin(), spadeCards.end(), cmpCardsRank);
		for (size_t i = spadeCards.size() - 5; i < spadeCards.size(); ++i)
		{
			flu.push_back(spadeCards[i]);
		}
		return flush(flu, true);
	}
	if (diaCards.size() == 5) return flush(diaCards, true);
	else if (diaCards.size() > 5)
	{
		hand_vector flu;
		std::sort(diaCards.begin(), diaCards.end(), cmpCardsRank);
		for (size_t i = diaCards.size() - 5; i < diaCards.size(); ++i)
		{
			flu.push_back(diaCards[i]);
		}
		return flush(flu, true);
	}
	if (hearCards.size() == 5) return flush(hearCards, true);
	else if (hearCards.size() > 5)
	{
		hand_vector flu;
		std::sort(hearCards.begin(), hearCards.end(), cmpCardsRank);
		for (size_t i = hearCards.size() - 5; i < hearCards.size(); ++i)
		{
			flu.push_back(hearCards[i]);
		}
		return flush(flu, true);
	}
	return flush(_hand, false);
}


Straight isStraight(const hand_vector & _hand)
{
	hand_vector tomod(_hand.begin(), _hand.end());
	auto cmpCardsRank = []( Card & lhs,  Card & rhs) -> bool {return lhs.getRank() < rhs.getRank(); };
	auto rvCardsRank = []( Card & lhs,  Card & rhs) -> bool {return lhs.getRank() > rhs.getRank(); };
	std::sort(tomod.begin(), tomod.end(), cmpCardsRank);

	hand_vector currentSf;
	hand_vector oldSf;
	int count = 1;
	bool foundSf = false;
	size_t compareSize = tomod.size() + 1;
	if (tomod[0].getRank() == 2 && containsRank(tomod, ace)) {
		tomod.erase(tomod.end() - 1);
		currentSf.push_back(Card(ace, spades));
		count++;
	}
	for (int i = 0; i < tomod.size() - 1; ++i)
	{
		if (count >= 5) {
			if (tomod.size() == compareSize) {
				return (Straight(currentSf, true));
			}
		}
		if (tomod[i + 1].getRank() - tomod[i].getRank() == 1)
		{
			if (currentSf.size() == 5)
			{
				currentSf.erase(currentSf.begin());
			}
			if (i == 0)currentSf.push_back(tomod[0]);
			currentSf.push_back(tomod[i + 1]);
			count++;
		}
		else {
			count = 1;
			oldSf = currentSf;
			currentSf.clear();
		}
	}
	if (currentSf.size() == 5) return (Straight(currentSf, true));
	else if (oldSf.size() == 5)return Straight(oldSf, true);
	else return Straight(_hand, false);
}
Trips isTrips(const hand_vector & sentHand)
{
	auto _hand = hand_vector(sentHand.begin(), sentHand.end());
	auto cmpCardsRank = []( Card & lhs,  Card & rhs) -> bool {return lhs.getRank() < rhs.getRank(); };
	auto rvCardsRank = []( Card & lhs,  Card & rhs) -> bool {return lhs.getRank() > rhs.getRank(); };
	hand_vector potTrips;
	std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
	std::map<int, int> counts;
	for (Card c : _hand)
	{
		counts[c.getRank()]++;
	}
	for (std::map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it)
	{
		if (it->second == 3)
		{
			for (int i = 0; i < 3; ++i) {
				potTrips.push_back(Card((Rank)(it->first),spades));
			}
			for (int i = 0; i < _hand.size(); ++i)
			{

			}
		}
	}
	if (potTrips.size() > 1)
	{
		std::sort(_hand.begin(), _hand.end(), rvCardsRank);
		unsigned counter = 0;
		for (unsigned i = 0; i < _hand.size(); ++i)
		{
			if (counter >= 2) break;
			if (_hand[i].getRank() != potTrips[0].getRank())
			{
				potTrips.push_back(_hand[i]);
				counter++;
			}
		}
		return Trips(potTrips, true);
	}
	return Trips(_hand, false);
}


TwoPair isTwoPair(const hand_vector & sentHand)
{
	auto _hand = hand_vector(sentHand.begin(), sentHand.end());
	auto cmpCardsRank = []( Card & lhs, Card & rhs) -> bool {return lhs.getRank() > rhs.getRank(); };
	int count = 0;
	std::map<int, int> counts;
	hand_vector twoPairs;
	for (Card c : _hand)
	{
		counts[c.getRank()]++;
	}
	for (std::map<int, int>::reverse_iterator it = counts.rbegin(); it != counts.rend(); ++it)
	{
		if (it->second == 2)
		{
			if (twoPairs.size() == 4)break;
			count++;
			twoPairs.push_back(Card((Rank)it->first, clubs));
			twoPairs.push_back(Card((Rank)it->first, clubs));
		}
	}
	if (count >= 2)
	{
		for (Card c : _hand)
		{
			std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
			if (c.getRank() != twoPairs[0].getRank() && c.getRank() != twoPairs[2].getRank())
			{
				twoPairs.push_back(c);
				break;
			}
		}
		return TwoPair(twoPairs, true);
	}
	return TwoPair(_hand, false);
}
singlePair isPair(const hand_vector & sentHand)
{
	hand_vector _hand(sentHand);
	auto cmpCardsRank = [](Card & lhs, Card & rhs) -> bool {return lhs.getRank() > rhs.getRank(); };
	int count = 0;
	std::map<int, int> counts;
	std::vector<Card> toret;
	for (Card c : _hand)
	{
		counts[c.getRank()]++;
	}
	for (std::map<int, int>::reverse_iterator it = counts.rbegin(); it != counts.rend(); ++it)
	{
		if (it->second == 2)
		{
			count++;
			toret.push_back(Card((Rank)it->first, clubs));
			toret.push_back(Card((Rank)it->first, clubs));
		}
	}
	if (count >= 1)
	{
		std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
		int loc_count = 0;
		for (Card c : _hand)
		{
			if (c.getRank() != toret[0].getRank())
			{
				toret.push_back(c);
				loc_count++;
				if (loc_count >= 3) break;
			}
		}
		return singlePair(toret, true);
	}
	return singlePair(toret, false);
}

highCard getHighCard(const hand_vector & sentHand)
{
	auto _hand = hand_vector(sentHand.begin(), sentHand.end());
	auto cmpCardsRank = []( Card & lhs, Card & rhs) -> bool {return lhs.getRank() > rhs.getRank(); };

	std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
	hand_vector high;
	for (int i = 0; i < 5; ++i)
	{
		high.push_back(_hand[i]);
	}
	return highCard(high);
}
hand_ptr evalHand(const hand_vector &_hand)
{
	if (isRoyalFlush(_hand)) return std::make_unique<Hand>(RoyalFlush());
	else if (isQuads(_hand)) return std::make_unique<Hand>(isQuads(_hand));
	else if (isFullHouse(_hand))return std::make_unique<Hand>(isFullHouse(_hand));
	else if (isStraightFlush(_hand)) return std::make_unique<Hand>(isStraightFlush(_hand));
	else if (isFlush(_hand))return std::make_unique<Hand>(isFlush(_hand));
	else if (isStraight(_hand))return std::make_unique<Hand>(isStraight(_hand));
	else if (isTrips(_hand))return std::make_unique<Hand>(isTrips(_hand));
	else if (isTwoPair(_hand))return std::make_unique<Hand>(isTwoPair(_hand));
	else if (isPair(_hand))return std::make_unique<Hand>(isPair(_hand));
	else return std::make_unique<Hand>(getHighCard(_hand));
}

bool operator ==(hand_vector a, hand_vector b)
{
	if (a.size() != b.size()) return false;
	auto cmpCardsRank = [](Card & lhs, Card & rhs) -> bool
	{
		if (lhs.getRank() < rhs.getRank()) return false;
		if (lhs.getRank() > rhs.getRank()) return true;
		if (lhs.getSuit() < rhs.getSuit()) return false;
		if (lhs.getSuit() > rhs.getSuit()) return true;
		return false;
	};
	std::sort(a.begin(), a.end(), cmpCardsRank);
	std::sort(b.begin(), b.end(), cmpCardsRank);


	for (unsigned i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
bool contains(const hand_vector & v, const Card & c1)
{
	for (Card c2 : v)
	{
		if (c2 == c1) return true;
	}
	return false;
}
bool containsRank(const hand_vector & v, Rank r)
{
	for (Card c2 : v)
	{
		if (c2.getRank() == r) return true;
	}
	return false;
}
std::ostream & operator<<(std::ostream & out, const hand_vector & h)
{
	for (Card c : h)
	{
		out << c.getRank() << std::endl;
	}
	return out;
}

std::ostream & operator<<(std::ostream & out, const hand_ptr & h)
{
	for (Card c : h->hand_)
	{
		std::cout << c.getRank() << std::endl;
	}
	return out;
}