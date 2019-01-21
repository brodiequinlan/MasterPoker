#include <Master.h>
#include <boost/test/auto_unit_test.hpp>
#include "Phases.hpp"
#include <iostream>



BOOST_AUTO_TEST_CASE(constructor)
{
	Deck deck;
	BOOST_CHECK(deck.getCards().size() == 52);

	Card a(ace, clubs);
	Card b = deck.getCards()[12];

	BOOST_CHECK(a == b);

	Card c(ace, hearts);
	Card d = deck.getCards()[51];

	BOOST_CHECK(c == d);
}

BOOST_AUTO_TEST_CASE(remove_card)
{
	Deck deck;
	BOOST_CHECK(deck.getCards().size() == 52);


	BOOST_CHECK(deck.removeCard(Card(ace, spades)) == true);
	BOOST_CHECK(deck.removeCard(Card(ace, hearts)) == true);
	BOOST_CHECK(deck.removeCard(Card(ace, spades)) == false);
	BOOST_CHECK(deck.removeCard(Card(ace, hearts)) == false);
	BOOST_CHECK(deck.getCards().size() == 50);
}

BOOST_AUTO_TEST_CASE(draw_card)
{
	Deck deck;
	deck.shuffle();
	Card x = deck.getCards()[0];
	Card c = deck.draw();
	BOOST_CHECK(deck.getCards().size() == 51);
	BOOST_CHECK(x == c);
	BOOST_CHECK(x != deck.draw());
	BOOST_CHECK(deck.getCards().size() == 50);
}
