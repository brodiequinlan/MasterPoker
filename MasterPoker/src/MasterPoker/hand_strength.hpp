#pragma once
#include <vector>
#include <memory>
#include "hands.hpp"
//not all strength functions have the same paramater setup (some require modification some dont, therefore some get non const copies (dont want origonal hand modified either) and some get const & for speed instead of copies
using hand_ptr = std::unique_ptr<baseHand>;
MASTER_API StraightFlush isStraightFlush(const hand & hand);
MASTER_API bool isRoyalFlush(const hand & hand);
MASTER_API quads isQuads(const hand & hand);
MASTER_API fullHouse isFullHouse(const hand & hand);
MASTER_API flush isFlush(const hand & hand);
MASTER_API Straight isStraight(const hand & hand);
MASTER_API Trips isTrips( hand hand);
MASTER_API TwoPair isTwoPair( hand hand);
MASTER_API singlePair isPair( hand & hand);
MASTER_API highCard getHighCard( hand hand);
MASTER_API hand_ptr getHand(hand & _hand);