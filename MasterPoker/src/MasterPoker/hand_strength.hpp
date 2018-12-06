#pragma once

#include "hands.hpp"
//not all strength functions have the same paramater setup (some require modification some dont, therefore some get non const copies (dont want origonal hand modified either) and some get const & for speed instead of copies
using hand = std::unique_ptr<baseHand>;
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
 hand evalHand(const hand_vector & _hand);