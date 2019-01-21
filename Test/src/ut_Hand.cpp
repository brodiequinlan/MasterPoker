
#include <boost/test/unit_test.hpp>
#include <Master.h>
#include "Phases.hpp"

#include <iostream>


#if defined(hand_tc)

BOOST_AUTO_TEST_CASE(ROYAL)
{
	hand_vector s = { Card(ace,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	BOOST_CHECK(isRoyalFlush(s));
	hand_vector c = { Card(ace,clubs),Card(king,clubs) ,Card(queen,clubs) ,Card(jack,clubs) ,Card(ten,clubs) };
	BOOST_CHECK(isRoyalFlush(c));
	hand_vector d = { Card(ace,diamonds),Card(king,diamonds) ,Card(queen,diamonds) ,Card(jack,diamonds) ,Card(ten,diamonds) };
	BOOST_CHECK(isRoyalFlush(d));
	hand_vector h = { Card(ace,hearts),Card(king,hearts) ,Card(queen,hearts) ,Card(jack,hearts) ,Card(ten,hearts) };
	BOOST_CHECK(isRoyalFlush(h));
	hand_vector n = { Card(ace,spades),Card(king,diamonds) ,Card(queen,hearts) ,Card(jack,hearts) ,Card(ten,hearts) };
	BOOST_CHECK(!isRoyalFlush(n));
}


BOOST_AUTO_TEST_CASE(SF)
{
	hand_vector s = { Card(ace,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	BOOST_CHECK(isStraightFlush(s).is);
	hand_vector c = { Card(ace,clubs),Card(king,clubs) ,Card(queen,clubs) ,Card(jack,clubs) ,Card(ten,clubs) };
	BOOST_CHECK(isStraightFlush(c).is);
	hand_vector d = { Card(ace,diamonds),Card(king,diamonds) ,Card(queen,diamonds) ,Card(jack,diamonds) ,Card(ten,diamonds) };
	BOOST_CHECK(isStraightFlush(d).is);
	hand_vector h = { Card(ace,hearts),Card(king,hearts) ,Card(queen,hearts) ,Card(jack,hearts) ,Card(ten,hearts) };
	BOOST_CHECK(isStraightFlush(h).is);

	hand_vector low = { Card(ace,spades),Card(two,spades) ,Card(three,spades) ,Card(four,spades) ,Card(five,spades) };
	BOOST_CHECK(isStraightFlush(low).is);
	hand_vector mid = { Card(six,spades), Card(nine,spades),Card(ten,spades) ,Card(jack,spades) ,Card(eight,spades) ,Card(seven,spades) };
	BOOST_CHECK(isStraightFlush(mid).is);
	hand_vector sup = { Card(nine,spades),Card(ten,spades) ,Card(jack,spades) ,Card(eight,spades) ,Card(seven,spades) };
	
	BOOST_CHECK(isStraightFlush(mid).hand_ == sup);

	hand_vector n = { Card(ace,spades),Card(king,diamonds) ,Card(queen,hearts) ,Card(jack,hearts) ,Card(ten,hearts) };
	BOOST_CHECK(!isStraightFlush(n).is);
}



BOOST_AUTO_TEST_CASE(QUADS)
{

	hand_vector low = { Card(ace,spades),Card(ace,diamonds) ,Card(ace,hearts) ,Card(two,spades) ,Card(two,hearts) };
	BOOST_CHECK(!isQuads(low).is);
	hand_vector mid = { Card(six,spades), Card(six,hearts),Card(six,diamonds) ,Card(six,clubs) ,Card(eight,spades) ,Card(seven,spades) };
	BOOST_CHECK(isQuads(mid).is);
}



BOOST_AUTO_TEST_CASE(FULLHOUSE)
{

	hand_vector is = { Card(ace,spades),Card(ace,diamonds) ,Card(ace,hearts) ,Card(two,spades) ,Card(two,hearts) };
	BOOST_CHECK(isFullHouse(is).is);
	hand_vector notfh = { Card(six,spades), Card(six,hearts),Card(six,diamonds) ,Card(six,clubs) ,Card(eight,spades) ,Card(seven,spades) };
	BOOST_CHECK(!isFullHouse(notfh).is);
}


BOOST_AUTO_TEST_CASE(FLUSH)
{

	hand_vector is = { Card(ace,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	BOOST_CHECK(isFlush(is).is);
	is = { Card(ace,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(two,spades),Card(two,diamonds),Card(two,hearts) };
	BOOST_CHECK(isFlush(is).is);
	hand_vector notfl = { Card(six,spades), Card(six,hearts),Card(six,diamonds) ,Card(six,clubs) ,Card(eight,spades) ,Card(seven,spades) };
	BOOST_CHECK(!isFullHouse(notfl).is);
}

BOOST_AUTO_TEST_CASE(STRAIGHT)
{

	hand_vector is = { Card(ace,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,clubs) ,Card(ten,spades) };
	BOOST_CHECK(isStraight(is).is);
	hand_vector notfl = { Card(six,spades), Card(six,spades),Card(six,spades) ,Card(six,clubs) ,Card(eight,spades) ,Card(seven,spades) };
	BOOST_CHECK(!isStraight(notfl).is);
}

BOOST_AUTO_TEST_CASE(TRIPS)
{

	hand_vector is = { Card(ace,spades),Card(ace,diamonds) ,Card(queen,spades) ,Card(jack,clubs) ,Card(ace,clubs) };
	BOOST_CHECK(isTrips(is).is);
	hand_vector notfl = { Card(six,spades), Card(six,spades),Card(six,spades) ,Card(six,clubs) ,Card(eight,spades) ,Card(seven,spades) };
	BOOST_CHECK(!isTrips(notfl).is);
}

BOOST_AUTO_TEST_CASE(TWOPAIR)
{

	hand_vector is = { Card(ace,clubs),Card(ace,clubs) ,Card(queen,clubs), Card(king,clubs),Card(queen,clubs),Card(jack,clubs),Card(two,clubs) };
	hand_vector sb = { Card(ace,clubs),Card(ace,clubs) ,Card(queen,clubs),Card(queen,clubs), Card(king,clubs) };
	BOOST_CHECK(isTwoPair(is).is);
	BOOST_CHECK(isTwoPair(is).hand_ == sb);
	hand_vector notfl = { Card(six,spades), Card(six,spades),Card(six,spades) ,Card(six,clubs) ,Card(eight,spades) ,Card(seven,spades) };
	BOOST_CHECK(!isTwoPair(notfl).is);

	hand_vector threepair = { Card(ace,clubs), Card(ace,clubs),Card(six,clubs) ,Card(six,clubs) ,Card(eight,clubs) ,Card(eight,clubs) };
	hand_vector sp = { Card(ace,clubs), Card(ace,clubs),Card(six,clubs) ,Card(eight,clubs) ,Card(eight,clubs) };
	BOOST_CHECK(isTwoPair(threepair).hand_ == sp);


	hand_vector s = { Card(ace,spades),Card(ace,clubs) ,Card(two,diamonds) ,Card(two,spades) ,Card(ten,spades) };
	BOOST_CHECK(isTwoPair(s).is);
}

BOOST_AUTO_TEST_CASE(ONEPAIR)
{
	BOOST_ASSERT(1 == 1);
	hand_vector is = { Card(ace,clubs),Card(ace,clubs) ,Card(queen,clubs), Card(king,clubs),Card(three,clubs),Card(jack,clubs),Card(two,clubs) };
	hand_vector sb = { Card(ace,clubs),Card(ace,clubs) ,Card(queen,clubs), Card(king,clubs),Card(jack,clubs) };
	BOOST_CHECK(isPair(is).is);
	BOOST_CHECK(isPair(is).hand_ == sb);
}
#endif