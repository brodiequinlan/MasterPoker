#include "mppch.h"

#include "hand_strength.hpp"

bool isRoyalFlush(const hand_vector & _hand)
{
	card as(ace, spades);
	card ks(king, spades);
	card qs(queen, spades);
	card js(jack, spades);
	card ts(ten, spades);

	card ac(ace, clubs);
	card kc(king, clubs);
	card qc(queen, clubs);
	card jc(jack, clubs);
	card tc(ten, clubs);

	card ad(ace, diamonds);
	card kd(king, diamonds);
	card qd(queen, diamonds);
	card jd(jack, diamonds);
	card td(ten, diamonds);

	card ah(ace, hearts);
	card kh(king, hearts);
	card qh(queen, hearts);
	card jh(jack, hearts);
	card th(ten, hearts);

	if (contains(_hand, as) && contains(_hand, ks) && contains(_hand, qs) && contains(_hand, js) && contains(_hand, ts)) return true;
	if (contains(_hand, ah) && contains(_hand, kh) && contains(_hand, qh) && contains(_hand, jh) && contains(_hand, th)) return true;
	if (contains(_hand, ad) && contains(_hand, kd) && contains(_hand, qd) && contains(_hand, jd) && contains(_hand, td)) return true;
	if (contains(_hand, ac) && contains(_hand, kc) && contains(_hand, qc) && contains(_hand, jc) && contains(_hand, tc)) return true;

	return false;
}

StraightFlush isStraightFlush(const hand_vector & _hand)
{
	hand_vector clubCards;
	hand_vector spadeCards;
	hand_vector diaCards;
	hand_vector hearCards;

	for (card c : _hand)
	{
		switch (c.suit)
		{
		case clubs:clubCards.push_back(c); break;
		case spades: spadeCards.push_back(c); break;
		case diamonds: diaCards.push_back(c); break;
		case hearts: hearCards.push_back(c); break;
		}
	}
	if (!(clubCards.size() >= 5 || spadeCards.size() >= 5 || diaCards.size() >= 5 || hearCards.size() >= 5)) return StraightFlush(_hand, false);
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank < rhs.rank; };
	auto rvCardsRank = [](const card & lhs, const card& rhs) -> bool {return lhs.rank > rhs.rank; };
	std::sort(clubCards.begin(), clubCards.end(), cmpCardsRank);
	std::sort(spadeCards.begin(), spadeCards.end(), cmpCardsRank);
	std::sort(diaCards.begin(), diaCards.end(), cmpCardsRank);
	std::sort(hearCards.begin(), hearCards.end(), cmpCardsRank);

	int count = 1;
	bool foundSf = false;
	hand_vector currentSf;
	hand_vector oldSf;
	size_t compareSize = spadeCards.size() + 1;
	if (spadeCards.size() >= 5)
	{
		card z(ace, spades);
		if (spadeCards[0].rank == 2 && contains(spadeCards, z)) {
			spadeCards.erase(spadeCards.end() - 1);
			currentSf.push_back(card(ace, spades));
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
			if (spadeCards[i + 1].rank - spadeCards[i].rank == 1 && spadeCards[i].suit == spadeCards[i + 1].suit)
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
		card z(ace, spades);
		if (clubCards[0].rank == 2 && contains(clubCards, z)) {
			clubCards.erase(clubCards.end() - 1);
			currentSf.push_back(card(ace, spades));
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
			if (clubCards[i + 1].rank - clubCards[i].rank == 1 && clubCards[i].suit == clubCards[i + 1].suit)
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
		card z(ace, spades);
		if (diaCards[0].rank == 2 && contains(diaCards, z)) {
			diaCards.erase(diaCards.end() - 1);
			currentSf.push_back(card(ace, spades));
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
			if (diaCards[i + 1].rank - diaCards[i].rank == 1 && diaCards[i].suit == diaCards[i + 1].suit)
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
		card z(ace, spades);
		if (hearCards[0].rank == 2 && contains(hearCards, z)) {
			hearCards.erase(hearCards.end() - 1);
			currentSf.push_back(card(ace, spades));
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
			if (hearCards[i + 1].rank - hearCards[i].rank == 1 && hearCards[i].suit == hearCards[i + 1].suit)
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
	cardRank quad = ace;
	cardRank high = ace;
	bool foundFour = false;
	std::map<cardRank, int> count;
	for (card c : _hand)
	{
		count[c.rank]++;
	}
	for (std::map<cardRank, int>::iterator it = count.begin(); it != count.end();)
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
	std::map<cardRank, int> count;
	bool twoCount = false, threeCount = false;
	bool multiThree = false;
	std::map<cardRank, int>::iterator currentTwo;
	std::map<cardRank, int>::iterator currentThree;
	std::map<cardRank, int>::iterator secondThree;
	for (card c : _hand)
	{
		count[c.rank]++;
	}
	for (std::map<cardRank, int>::iterator it = count.begin(); it != count.end(); ++it)
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

	for (card c : _hand)
	{
		switch (c.suit)
		{
		case clubs:clubCards.push_back(c); break;
		case spades: spadeCards.push_back(c); break;
		case diamonds: diaCards.push_back(c); break;
		case hearts: hearCards.push_back(c); break;
		}
	}
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank < rhs.rank; };
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
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank < rhs.rank; };
	auto rvCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank > rhs.rank; };
	std::sort(tomod.begin(), tomod.end(), cmpCardsRank);

	hand_vector currentSf;
	hand_vector oldSf;
	int count = 1;
	bool foundSf = false;
	size_t compareSize = tomod.size() + 1;
	if (tomod[0].rank == 2 && containsRank(tomod, ace)) {
		tomod.erase(tomod.end() - 1);
		currentSf.push_back(card(ace, spades));
		count++;
	}
	for (int i = 0; i < tomod.size() - 1; ++i)
	{
		if (count >= 5) {
			if (tomod.size() == compareSize) {
				return (Straight(currentSf, true));
			}
		}
		if (tomod[i + 1].rank - tomod[i].rank == 1)
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
	auto _hand = hand_vector(sentHand.begin(),sentHand.end());
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank < rhs.rank; };
	auto rvCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank > rhs.rank; };
	hand_vector potTrips;
	std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
	std::map<int, int> counts;
	for (card c : _hand)
	{
		counts[c.rank]++;
	}
	for (std::map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it)
	{
		if (it->second == 3)
		{
			for (int i = 0; i < 3; ++i) {
				potTrips.push_back(card((cardRank)(it->first)));
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
			if (_hand[i].rank != potTrips[0].rank)
			{
				potTrips.push_back(_hand[i]);
				counter++;
			}
		}
		return Trips(potTrips, true);
	}
	return Trips(_hand, false);
}


TwoPair isTwoPair( const hand_vector & sentHand)
{
	auto _hand = hand_vector(sentHand.begin(), sentHand.end());
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank > rhs.rank; };
	int count = 0;
	std::map<int, int> counts;
	hand_vector twoPairs;
	for (card c : _hand)
	{
		counts[c.rank]++;
	}
	for (std::map<int, int>::reverse_iterator it = counts.rbegin(); it != counts.rend(); ++it)
	{
		if (it->second == 2)
		{
			if (twoPairs.size() == 4)break;
			count++;
			twoPairs.push_back(card((cardRank)it->first, clubs));
			twoPairs.push_back(card((cardRank)it->first,clubs));
		}
	}
	if (count >= 2)
	{
		for (card c : _hand)
		{
			std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
			if (c.rank != twoPairs[0].rank && c.rank != twoPairs[2].rank)
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
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank > rhs.rank; };
	int count = 0;
	std::map<int, int> counts;
	std::vector<card> toret;
	for (card c : _hand)
	{
		counts[c.rank]++;
	}
	for (std::map<int, int>::reverse_iterator it = counts.rbegin(); it != counts.rend(); ++it)
	{
		if (it->second == 2)
		{
			count++;
			toret.push_back(card((cardRank)it->first,clubs));
			toret.push_back(card((cardRank)it->first,clubs));
		}
	}
	if (count >= 1)
	{
		std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
		int loc_count = 0;
		for (card c : _hand)
		{
			if (c.rank != toret[0].rank)
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
	auto cmpCardsRank = [](const card & lhs, const card & rhs) -> bool {return lhs.rank > rhs.rank; };

	std::sort(_hand.begin(), _hand.end(), cmpCardsRank);
	hand_vector high;
	for (int i = 0; i < 5; ++i)
	{
		high.push_back(_hand[i]);
	}
	return highCard(high);
}
hand evalHand(const hand_vector &_hand)
{
	if (isRoyalFlush(_hand)) return std::make_unique<baseHand>(RoyalFlush());
	else if (isQuads(_hand)) return std::make_unique<baseHand>(isQuads(_hand));
	else if (isFullHouse(_hand))return std::make_unique<baseHand>(isFullHouse(_hand));
	else if (isStraightFlush(_hand)) return std::make_unique<baseHand>(isStraightFlush(_hand));
	else if (isFlush(_hand))return std::make_unique<baseHand>(isFlush(_hand));
	else if (isStraight(_hand))return std::make_unique<baseHand>(isStraight(_hand));
	else if (isTrips(_hand))return std::make_unique<baseHand>(isTrips(_hand));
	else if (isTwoPair(_hand))return std::make_unique<baseHand>(isTwoPair(_hand));
	else if (isPair(_hand))return std::make_unique<baseHand>(isPair(_hand));
	else return std::make_unique<baseHand>(getHighCard(_hand));
}