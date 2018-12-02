#pragma once
#include <vector>
#include <memory>
#include "hands.hpp"
//not all strength functions have the same paramater setup (some require modification some dont, therefore some get non const copies (dont want origonal hand modified either) and some get const & for speed instead of copies
using hand = std::unique_ptr<baseHand>;
MASTER_API StraightFlush isStraightFlush(const hand_vector & hand);
MASTER_API bool isRoyalFlush(const hand_vector & hand);
MASTER_API quads isQuads(const hand_vector & hand);
MASTER_API fullHouse isFullHouse(const hand_vector & hand);
MASTER_API flush isFlush(const hand_vector & hand);
MASTER_API Straight isStraight(const hand_vector & hand);
MASTER_API Trips isTrips(const hand_vector & hand);
MASTER_API TwoPair isTwoPair(const hand_vector & hand);
MASTER_API singlePair isPair(const hand_vector & hand);
MASTER_API highCard getHighCard(const hand_vector & hand);
MASTER_API hand evalHand(const hand_vector & _hand);