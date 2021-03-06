#include <Master.h>
#include <boost/test/auto_unit_test.hpp>
#include "ut_phases.hpp"
#include <iostream>
#if TEST_GETHAND
BOOST_AUTO_TEST_CASE(GETHAND)
{
	hand_vector s = { card(eight,clubs),card(eight,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr gottenHand = evalHand(s);
	BOOST_CHECK(gottenHand->ranking == 8);

	s = { card(nine,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	gottenHand = evalHand(s);
	BOOST_CHECK(gottenHand->ranking == 1);

	s = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	gottenHand = evalHand(s);
	BOOST_CHECK(gottenHand->ranking == 0);

	s = { card(nine,clubs),card(nine,spades) ,card(queen,clubs) ,card(queen,spades) ,card(ten,spades) };
	gottenHand = evalHand(s);
	BOOST_CHECK(gottenHand->ranking == 7);
}
#endif
#if TEST_OPGREATER
BOOST_AUTO_TEST_CASE(OPGREATER)
{
	hand_vector s = { card(nine,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
	hand_ptr hand2 = evalHand(s);
	BOOST_CHECK(!(*hand1 > *hand2));
	BOOST_CHECK(!(*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_ROYAL)
{
	hand_vector s = { card(nine,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
}
BOOST_AUTO_TEST_CASE(GR_SF)
{
	hand_vector s = { card(nine,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
	hand_ptr hand2 = evalHand(s);
	
	hand1 = evalHand(s);
	s = { card(nine,spades),card(eight,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1 > *hand2));
	s = { card(nine,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand1 = evalHand(s);
	s = { card(nine,spades),card(eight,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1 > *hand2));
}
BOOST_AUTO_TEST_CASE(GR_QUADS)
{
	hand_vector s = { card(nine,spades),card(nine,clubs) ,card(nine,diamonds) ,card(nine,hearts) ,card(ace,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(nine,spades),card(nine,clubs) ,card(nine,diamonds) ,card(nine,hearts) ,card(king,spades) };
	hand_ptr hand2 = evalHand(s);
	BOOST_CHECK((*hand1 > *hand2));

	s = { card(nine,spades),card(nine,clubs) ,card(nine,diamonds) ,card(nine,hearts) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(ten,spades),card(ten,clubs) ,card(ten,diamonds) ,card(ten,hearts) ,card(king,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_FULLHOUSE)
{
	hand_vector s = { card(nine,spades),card(nine,clubs) ,card(nine,diamonds) ,card(ace,hearts) ,card(ace,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(ten,spades),card(ten,clubs) ,card(ten,diamonds) ,card(king,hearts) ,card(king,spades) };
	hand_ptr hand2 = evalHand(s);
	BOOST_CHECK((*hand2 > *hand1));

	s = { card(nine,spades),card(nine,clubs) ,card(nine,diamonds) ,card(ace,hearts) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(nine,spades),card(nine,clubs) ,card(nine,diamonds) ,card(king,hearts) ,card(king,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1 > *hand2));
}
BOOST_AUTO_TEST_CASE(GR_FLUSH)
{
	hand_vector s = { card(ace,spades),card(two,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(ace,spades),card(eight,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand2 = evalHand(s);
	BOOST_CHECK((*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_STRAIGHT)
{
	hand_vector s = { card(ace,spades),card(king,clubs) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(nine,spades),card(eight,clubs) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand2 = evalHand(s);
	BOOST_CHECK((*hand1 > *hand2));
}
BOOST_AUTO_TEST_CASE(GR_TRIPS)
{
	hand_vector s = { card(ace,spades),card(ace,clubs) ,card(ace,diamonds) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(ace,spades),card(ace,clubs) ,card(ace,diamonds) ,card(nine,spades) ,card(ten,spades) };
	hand_ptr hand2 = evalHand(s);
	BOOST_CHECK((*hand1 > *hand2));
	BOOST_CHECK(!(*hand2 > *hand1));

	s = { card(ace,spades),card(ace,clubs) ,card(ace,diamonds) ,card(jack,spades) ,card(ten,spades) };
	hand1 = evalHand(s);
	s = { card(king,spades),card(king,clubs) ,card(king,diamonds) ,card(nine,spades) ,card(ten,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1> *hand2));
}
BOOST_AUTO_TEST_CASE(GR_TWOPAIR)
{
	hand_vector s = { card(ace,spades),card(ace,clubs) ,card(jack,diamonds) ,card(jack,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(ace,spades),card(ace,clubs) ,card(nine,diamonds) ,card(nine,spades) ,card(ten,spades) };
	hand_ptr hand2 = evalHand(s);
	std::cout << std::endl;
	BOOST_CHECK((*hand1> *hand2));

	s = { card(ten,spades),card(ten,clubs) ,card(jack,diamonds) ,card(jack,spades) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(ace,spades),card(ace,clubs) ,card(nine,diamonds) ,card(nine,spades) ,card(ten,spades) };
	hand2 = evalHand(s);
	std::cout << std::endl;
	BOOST_CHECK((*hand2> *hand1));

	s = { card(ten,spades),card(ten,clubs) ,card(jack,diamonds) ,card(jack,spades) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(ace,spades),card(ace,clubs) ,card(two,diamonds) ,card(two,spades) ,card(ten,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand2> *hand1));
}
BOOST_AUTO_TEST_CASE(GR_PAIR)
{
	hand_vector s = { card(ace,spades),card(ace,clubs) ,card(jack,diamonds) ,card(queen,spades) ,card(ten,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(king,spades),card(king,clubs) ,card(nine,diamonds) ,card(three,spades) ,card(ten,spades) };
	hand_ptr hand2 = evalHand(s);
	std::cout << std::endl;
	BOOST_CHECK((*hand1> *hand2));

	s = { card(three,spades),card(four,clubs) ,card(jack,diamonds) ,card(jack,spades) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(three,spades),card(four,clubs) ,card(jack,diamonds) ,card(jack,spades) ,card(king,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1> *hand2));

	s = { card(three,spades),card(three,clubs) ,card(king,diamonds) ,card(jack,spades) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(three,spades),card(four,clubs) ,card(jack,diamonds) ,card(jack,spades) ,card(king,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand2> *hand1));

	s = { card(queen,spades),card(queen,clubs) ,card(jack,diamonds) ,card(eight,spades) ,card(seven,spades) };
	hand1 = evalHand(s);
	s = { card(king,spades),card(king,clubs) ,card(jack,diamonds) ,card(eight,spades) ,card(seven,spades) };
	hand2 = evalHand(s);

	BOOST_CHECK((*hand2> *hand1));
}
BOOST_AUTO_TEST_CASE(GR_HIGHCARD)
{
	hand_vector s = { card(ace,spades),card(king,clubs) ,card(jack,diamonds) ,card(queen,spades) ,card(four,spades) };
	hand_ptr hand1 = evalHand(s);
	s = { card(ace,spades),card(king,clubs) ,card(jack,diamonds) ,card(queen,spades) ,card(five,spades) };
	hand_ptr hand2 = evalHand(s);
	std::cout << std::endl;
	BOOST_CHECK((*hand2> *hand1));

	s = { card(three,spades),card(four,clubs) ,card(jack,diamonds) ,card(ten,spades) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(three,spades),card(four,clubs) ,card(jack,diamonds) ,card(ten,spades) ,card(king,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1> *hand2));

	s = { card(three,spades),card(five,clubs) ,card(king,diamonds) ,card(jack,spades) ,card(ace,spades) };
	hand1 = evalHand(s);
	s = { card(three,spades),card(four,clubs) ,card(jack,diamonds) ,card(ace,spades) ,card(king,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1> *hand2));

	s = { card(king,spades),card(king,clubs) ,card(king,diamonds) ,card(four,spades) ,card(four,spades) };
	hand1 = evalHand(s);
	s = { card(queen,spades),card(queen,clubs) ,card(four,diamonds) ,card(four,spades) ,card(ten,spades) };
	hand2 = evalHand(s);
	BOOST_CHECK((*hand1> *hand2));
}
#endif