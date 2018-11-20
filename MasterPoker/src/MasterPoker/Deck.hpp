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
public:
	const deck_type& getCards();
	Deck();
	~Deck();
};

