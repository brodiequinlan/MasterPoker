#pragma once
#include <vector>
#include "hands.hpp"
#include "hand_strength.hpp"
#include "Deck.hpp"
#include <memory>
using hand_vector = std::vector<card>;
MASTER_API void printHand(const hand_vector& h);
MASTER_API void printDeck(const Deck::deck_type& h);
MASTER_API void printHandPtr(const hand& h);
MASTER_API bool contains(const hand_vector & v, const card & c1);
MASTER_API bool contains(const hand_vector & v, const card & c1);
MASTER_API bool containsRank(const hand_vector& v, cardRank r);
MASTER_API bool operator !=(const card& c, const card& b);
MASTER_API bool operator ==(hand_vector a, hand_vector b);