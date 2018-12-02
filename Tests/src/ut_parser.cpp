#include <boost/test/auto_unit_test.hpp>
#include "ut_phases.hpp"
#include <Master.h>
#include <iostream>
#if TEST_PARSER

BOOST_AUTO_TEST_CASE(IO_TEST)
{
	Parser parser;

	hand_vector test = { card(ace, spades), card(ace, clubs) };
	
	BOOST_CHECK(test == parser.parseHand("asac"));


	test = { card(seven, spades), card(seven, clubs) };

	BOOST_CHECK(test == parser.parseHand("7s7c"));


	test = { card(ace, spades), card(ace, clubs) };

	BOOST_CHECK(test != parser.parseHand("asad"));


	test = { card(two, diamonds), card(three, clubs) };

	BOOST_CHECK(test == parser.parseHand("2d3c"));


}




#endif