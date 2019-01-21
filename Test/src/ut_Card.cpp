#define BOOST_TEST_MODULE poker_engine

#include <boost/test/unit_test.hpp>


#include <Master.h>

BOOST_AUTO_TEST_CASE(card_ops)
{
	Card a(ace, clubs);
	Card b(king, hearts);
	Card c(ace,clubs);
	
	BOOST_CHECK(c > b);
	BOOST_CHECK(c >= b);
	BOOST_CHECK(b < c);
	BOOST_CHECK(b <= c);
	BOOST_CHECK(c == a);
}