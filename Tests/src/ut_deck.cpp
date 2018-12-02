#include <boost/test/auto_unit_test.hpp>
#include "ut_phases.hpp"
#include <Master.h>
#include <iostream>


#if TEST_DECK_CONSTRUCTOR
BOOST_AUTO_TEST_CASE(constructor)
{
	Deck deck;
	BOOST_CHECK(deck.getCards().size() == 52);

	std::shared_ptr<card> testcard = std::make_shared<card>(ace, clubs);

	BOOST_CHECK(deck.getCards()[12] == *testcard);

	std::shared_ptr<card> testcard2 = std::make_shared<card>(ace, hearts);

	BOOST_CHECK(deck.getCards()[51] == *testcard2);
}
#endif
#if TEST_DECK_REMOVE
BOOST_AUTO_TEST_CASE(remove_card)
{
	Deck deck;
	BOOST_CHECK(deck.getCards().size() == 52);


	BOOST_CHECK(deck.removeCard(card(ace, spades)) == true);
	BOOST_CHECK(deck.removeCard(card(ace, hearts)) == true);
	BOOST_CHECK(deck.removeCard(card(ace, spades)) == false);
	BOOST_CHECK(deck.removeCard(card(ace, hearts)) == false);
	BOOST_CHECK(deck.getCards().size() == 50);
}
#endif
#if TEST_DECK_DRAW
BOOST_AUTO_TEST_CASE(draw_card)
{
	Deck deck;
	deck.shuffle();
	card x = deck.getCards()[0];
	card c = deck.draw();
	BOOST_CHECK(deck.getCards().size() == 51);
	BOOST_CHECK(x == c);
	BOOST_CHECK(x != deck.draw());
	BOOST_CHECK(deck.getCards().size() == 50);
}
#endif