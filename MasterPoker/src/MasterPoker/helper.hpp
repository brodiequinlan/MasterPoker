#pragma once
#include <vector>
#include "hands.hpp"
#include "hand_strength.hpp"
#include "Deck.hpp"
#include <memory>
using hand = std::vector<card>;
MASTER_API void printHand(hand h);
MASTER_API void printDeck(Deck::deck_type h);
MASTER_API void printHandPtr(hand_ptr h);
MASTER_API bool contains(const hand & v, const card & c1);
MASTER_API bool contains(const hand & v, const card & c1);
MASTER_API bool containsRank(const hand& v, cardRank r);
MASTER_API bool operator !=(const card& c, const card& b);
MASTER_API bool operator ==( hand a, hand b);
