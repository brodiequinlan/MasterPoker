#define BOOST_TEST_MODULE poker
#include <boost/test/unit_test.hpp>

#include <Master.h>
#include "ut_phases.hpp"
#include <iostream>




#if TEST_ROYAL
BOOST_AUTO_TEST_CASE(ROYAL)
{
	hand s = {card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	BOOST_CHECK(isRoyalFlush(s));
	hand c = { card(ace,clubs),card(king,clubs) ,card(queen,clubs) ,card(jack,clubs) ,card(ten,clubs) };
	BOOST_CHECK(isRoyalFlush(c));
	hand d = { card(ace,diamonds),card(king,diamonds) ,card(queen,diamonds) ,card(jack,diamonds) ,card(ten,diamonds) };
	BOOST_CHECK(isRoyalFlush(d));
	hand h = { card(ace,hearts),card(king,hearts) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(isRoyalFlush(h));
	hand n = { card(ace,spades),card(king,diamonds) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(!isRoyalFlush(n));
}
#endif

#if TEST_SF
BOOST_AUTO_TEST_CASE(SF)
{
	hand s = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	BOOST_CHECK(isStraightFlush(s).is);
	hand c = { card(ace,clubs),card(king,clubs) ,card(queen,clubs) ,card(jack,clubs) ,card(ten,clubs) };
	BOOST_CHECK(isStraightFlush(c).is);
	hand d = { card(ace,diamonds),card(king,diamonds) ,card(queen,diamonds) ,card(jack,diamonds) ,card(ten,diamonds) };
	BOOST_CHECK(isStraightFlush(d).is);
	hand h = { card(ace,hearts),card(king,hearts) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(isStraightFlush(h).is);
	
	hand low = { card(ace,spades),card(two,spades) ,card(three,spades) ,card(four,spades) ,card(five,spades) };
	BOOST_CHECK(isStraightFlush(low).is);
	hand mid = { card(six,spades), card(nine,spades),card(ten,spades) ,card(jack,spades) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(isStraightFlush(mid).is);
	hand sup = { card(nine,spades),card(ten,spades) ,card(jack,spades) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(isStraightFlush(mid).hand_ == sup);

	hand n = { card(ace,spades),card(king,diamonds) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(!isStraightFlush(n).is);
}
#endif

#if TEST_QUADS
BOOST_AUTO_TEST_CASE(QUADS)
{
	
	hand low = { card(ace,spades),card(ace,diamonds) ,card(ace,hearts) ,card(two,spades) ,card(two,hearts) };
	BOOST_CHECK(!isQuads(low).is);
	hand mid = { card(six,spades), card(six,hearts),card(six,diamonds) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(isQuads(mid).is);
}
#endif

#if TEST_FH
BOOST_AUTO_TEST_CASE(FULLHOUSE)
{

	hand is = { card(ace,spades),card(ace,diamonds) ,card(ace,hearts) ,card(two,spades) ,card(two,hearts) };
	BOOST_CHECK(isFullHouse(is).is);
	hand notfh = { card(six,spades), card(six,hearts),card(six,diamonds) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isFullHouse(notfh).is);
}
#endif

#if TEST_FLUSH
BOOST_AUTO_TEST_CASE(FLUSH)
{

	hand is = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	BOOST_CHECK(isFlush(is).is);
	is = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(two,spades),card(two,diamonds),card(two,hearts) };
	BOOST_CHECK(isFlush(is).is);
	hand notfl = { card(six,spades), card(six,hearts),card(six,diamonds) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isFullHouse(notfl).is);
}
#endif

#if TEST_STRAIGHT
BOOST_AUTO_TEST_CASE(STRAIGHT)
{

	hand is = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,clubs) ,card(ten,spades) };
	BOOST_CHECK(isStraight(is).is);
	hand notfl = { card(six,spades), card(six,spades),card(six,spades) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isStraight(notfl).is);
}
#endif

#if TEST_TRIPS
BOOST_AUTO_TEST_CASE(TRIPS)
{

	hand is = { card(ace,spades),card(ace,diamonds) ,card(queen,spades) ,card(jack,clubs) ,card(ace,clubs) };
	BOOST_CHECK(isTrips(is).is);
	hand notfl = { card(six,spades), card(six,spades),card(six,spades) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isTrips(notfl).is);
}
#endif

#if TEST_TWOPAIR
BOOST_AUTO_TEST_CASE(TWOPAIR)
{

	hand is = { card(ace),card(ace) ,card(queen), card(king),card(queen),card(jack),card(two) };
	hand sb = { card(ace),card(ace) ,card(queen), card(king),card(queen) };
	BOOST_CHECK(isTwoPair(is).is);
	BOOST_CHECK(isTwoPair(is).hand_ == sb);
	hand notfl = { card(six,spades), card(six,spades),card(six,spades) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isTwoPair(notfl).is);

	hand threepair = { card(ace), card(ace),card(six) ,card(six) ,card(eight) ,card(eight) };
	hand sp = { card(ace), card(ace),card(six) ,card(eight) ,card(eight) };
	BOOST_CHECK(isTwoPair(threepair).hand_ == sp);


	hand s = { card(ace,spades),card(ace,clubs) ,card(two,diamonds) ,card(two,spades) ,card(ten,spades) };
	BOOST_CHECK(isTwoPair(s).is);
}
#endif

#if TEST_PAIR
BOOST_AUTO_TEST_CASE(ONEPAIR)
{
	BOOST_ASSERT(1 == 1);
	hand is = { card(ace),card(ace) ,card(queen), card(king),card(three),card(jack),card(two) };
	hand sb = { card(ace),card(ace) ,card(queen), card(king),card(jack) };
	BOOST_CHECK(isPair(is).is);
	BOOST_CHECK(isPair(is).hand_ == sb);
}
#endif
