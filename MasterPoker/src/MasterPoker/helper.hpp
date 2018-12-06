#pragma once

#include "hands.hpp"
#include "hand_strength.hpp"

using hand_vector = std::vector<card>;
void printHand(const hand_vector& h);
 void printDeck(const Deck::deck_type& h);
 void printHandPtr(const hand& h);
 bool contains(const hand_vector & v, const card & c1);
 bool contains(const hand_vector & v, const card & c1);
 bool containsRank(const hand_vector& v, cardRank r);
 bool operator !=(const card& c, const card& b);
 bool operator ==(hand_vector a, hand_vector b);