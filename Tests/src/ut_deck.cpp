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

	BOOST_CHECK(*deck.getCards()[12] == *testcard);

	std::shared_ptr<card> testcard2 = std::make_shared<card>(ace, hearts);

	BOOST_CHECK(*deck.getCards()[51] == *testcard2);
}
#endif