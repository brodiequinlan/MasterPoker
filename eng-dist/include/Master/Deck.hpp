#pragma once
#include <Master/Card.hpp>
#include <vector>

class Deck
{
private:
	std::vector<Card> cards;
	std::vector<Card> discards;
	void fill();
public:
	const std::vector<Card>& getCards();
	bool removeCard(Card x);
	bool removeCardF(Card x);
	Card& draw();
	void shuffle();
	void reset();
	Deck();
	~Deck();
};

