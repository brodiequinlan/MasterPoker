#pragma once
#include "Core.h"
#include "card.hpp"
#include <memory>
#include <vector>
class MASTER_API Deck
{
public:
	using deck_type = std::vector<std::shared_ptr<card>>;
private:
	deck_type cards;
	void fill();
public:
	const deck_type& getCards();
	bool removeCard(card x);
	card draw();
	void shuffle();
	Deck();
	~Deck();
};

