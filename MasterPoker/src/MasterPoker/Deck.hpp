#pragma once
#include "Core.h"
#include "card.hpp"
#include <memory>
#include <random>
#include <vector>
class MASTER_API Deck
{
public:
	using deck_type = std::vector<std::shared_ptr<card>>;
private:
	deck_type cards;
	deck_type discards;
	void fill();
public:
	const deck_type& getCards();
	bool removeCard(card x);
	bool removeCardF(card x);
	card draw();
	void shuffle();
	void reset();
	Deck();
	~Deck();
};

