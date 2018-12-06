#include <Master.h>
#define BOOST_TEST_MODULE poker
#include <boost/test/unit_test.hpp>
#include "ut_phases.hpp"
#include <iostream>




#if TEST_ROYAL
BOOST_AUTO_TEST_CASE(ROYAL)
{
	hand_vector s = {card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	BOOST_CHECK(isRoyalFlush(s));
	hand_vector c = { card(ace,clubs),card(king,clubs) ,card(queen,clubs) ,card(jack,clubs) ,card(ten,clubs) };
	BOOST_CHECK(isRoyalFlush(c));
	hand_vector d = { card(ace,diamonds),card(king,diamonds) ,card(queen,diamonds) ,card(jack,diamonds) ,card(ten,diamonds) };
	BOOST_CHECK(isRoyalFlush(d));
	hand_vector h = { card(ace,hearts),card(king,hearts) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(isRoyalFlush(h));
	hand_vector n = { card(ace,spades),card(king,diamonds) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(!isRoyalFlush(n));
}
#endif

#if TEST_SF
BOOST_AUTO_TEST_CASE(SF)
{
	hand_vector s = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	BOOST_CHECK(isStraightFlush(s).is);
	hand_vector c = { card(ace,clubs),card(king,clubs) ,card(queen,clubs) ,card(jack,clubs) ,card(ten,clubs) };
	BOOST_CHECK(isStraightFlush(c).is);
	hand_vector d = { card(ace,diamonds),card(king,diamonds) ,card(queen,diamonds) ,card(jack,diamonds) ,card(ten,diamonds) };
	BOOST_CHECK(isStraightFlush(d).is);
	hand_vector h = { card(ace,hearts),card(king,hearts) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(isStraightFlush(h).is);
	
	hand_vector low = { card(ace,spades),card(two,spades) ,card(three,spades) ,card(four,spades) ,card(five,spades) };
	BOOST_CHECK(isStraightFlush(low).is);
	hand_vector mid = { card(six,spades), card(nine,spades),card(ten,spades) ,card(jack,spades) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(isStraightFlush(mid).is);
	hand_vector sup = { card(nine,spades),card(ten,spades) ,card(jack,spades) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(isStraightFlush(mid).hand_ == sup);

	hand_vector n = { card(ace,spades),card(king,diamonds) ,card(queen,hearts) ,card(jack,hearts) ,card(ten,hearts) };
	BOOST_CHECK(!isStraightFlush(n).is);
}
#endif

#if TEST_QUADS
BOOST_AUTO_TEST_CASE(QUADS)
{
	
	hand_vector low = { card(ace,spades),card(ace,diamonds) ,card(ace,hearts) ,card(two,spades) ,card(two,hearts) };
	BOOST_CHECK(!isQuads(low).is);
	hand_vector mid = { card(six,spades), card(six,hearts),card(six,diamonds) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(isQuads(mid).is); 
}
#endif

#if TEST_FH
BOOST_AUTO_TEST_CASE(FULLHOUSE)
{

	hand_vector is = { card(ace,spades),card(ace,diamonds) ,card(ace,hearts) ,card(two,spades) ,card(two,hearts) };
	BOOST_CHECK(isFullHouse(is).is);
	hand_vector notfh = { card(six,spades), card(six,hearts),card(six,diamonds) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isFullHouse(notfh).is);
}
#endif

#if TEST_FLUSH
BOOST_AUTO_TEST_CASE(FLUSH)
{

	hand_vector is = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(ten,spades) };
	BOOST_CHECK(isFlush(is).is);
	is = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,spades) ,card(two,spades),card(two,diamonds),card(two,hearts) };
	BOOST_CHECK(isFlush(is).is);
	hand_vector notfl = { card(six,spades), card(six,hearts),card(six,diamonds) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isFullHouse(notfl).is);
}
#endif

#if TEST_STRAIGHT
BOOST_AUTO_TEST_CASE(STRAIGHT)
{

	hand_vector is = { card(ace,spades),card(king,spades) ,card(queen,spades) ,card(jack,clubs) ,card(ten,spades) };
	BOOST_CHECK(isStraight(is).is);
	hand_vector notfl = { card(six,spades), card(six,spades),card(six,spades) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isStraight(notfl).is);
}
#endif

#if TEST_TRIPS
BOOST_AUTO_TEST_CASE(TRIPS)
{

	hand_vector is = { card(ace,spades),card(ace,diamonds) ,card(queen,spades) ,card(jack,clubs) ,card(ace,clubs) };
	BOOST_CHECK(isTrips(is).is);
	hand_vector notfl = { card(six,spades), card(six,spades),card(six,spades) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isTrips(notfl).is);
}
#endif

#if TEST_TWOPAIR
BOOST_AUTO_TEST_CASE(TWOPAIR)
{

	hand_vector is = { card(ace,clubs),card(ace,clubs) ,card(queen,clubs), card(king,clubs),card(queen,clubs),card(jack,clubs),card(two,clubs) };
	hand_vector sb = { card(ace,clubs),card(ace,clubs) ,card(queen,clubs),card(queen,clubs), card(king,clubs) };
	BOOST_CHECK(isTwoPair(is).is);
	BOOST_CHECK(isTwoPair(is).hand_ == sb);
	hand_vector notfl = { card(six,spades), card(six,spades),card(six,spades) ,card(six,clubs) ,card(eight,spades) ,card(seven,spades) };
	BOOST_CHECK(!isTwoPair(notfl).is);

	hand_vector threepair = { card(ace,clubs), card(ace,clubs),card(six,clubs) ,card(six,clubs) ,card(eight,clubs) ,card(eight,clubs) };
	hand_vector sp = { card(ace,clubs), card(ace,clubs),card(six,clubs) ,card(eight,clubs) ,card(eight,clubs) };
	BOOST_CHECK(isTwoPair(threepair).hand_ == sp);


	hand_vector s = { card(ace,spades),card(ace,clubs) ,card(two,diamonds) ,card(two,spades) ,card(ten,spades) };
	BOOST_CHECK(isTwoPair(s).is);
}
#endif

#if TEST_PAIR
BOOST_AUTO_TEST_CASE(ONEPAIR)
{
	BOOST_ASSERT(1 == 1);
	hand_vector is = { card(ace,clubs),card(ace,clubs) ,card(queen,clubs), card(king,clubs),card(three,clubs),card(jack,clubs),card(two,clubs) };
	hand_vector sb = { card(ace,clubs),card(ace,clubs) ,card(queen,clubs), card(king,clubs),card(jack,clubs) };
	BOOST_CHECK(isPair(is).is);
	BOOST_CHECK(isPair(is).hand_ == sb);  
}
#endif
