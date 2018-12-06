#pragma once

class Deck
{
public:
	 using deck_type = std::vector<card>;
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

