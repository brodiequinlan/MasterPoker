#include <Master.h>
#include <boost/test/auto_unit_test.hpp>
#include "Phases.hpp"
#include <iostream>

#if defined(engine_tc)
BOOST_AUTO_TEST_CASE(GETHAND)
{
	Evaluator eval;
	hand_vector s = { Card(eight,clubs),Card(eight,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr gottenHand = eval.evauluate(s);
	BOOST_CHECK(gottenHand->ranking == 8);

	s = { Card(nine,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	gottenHand = eval.evauluate(s);
	BOOST_CHECK(gottenHand->ranking == 1);

	s = { Card(ace,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	gottenHand = eval.evauluate(s);
	BOOST_CHECK(gottenHand->ranking == 0);

	s = { Card(nine,clubs),Card(nine,spades) ,Card(queen,clubs) ,Card(queen,spades) ,Card(ten,spades) };
	gottenHand = eval.evauluate(s);
	BOOST_CHECK(gottenHand->ranking == 7);
}

BOOST_AUTO_TEST_CASE(OPGREATER)
{
	Evaluator eval;
	hand_vector s = { Card(nine,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK(!(*hand1 > *hand2));
	BOOST_CHECK(!(*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_ROYAL)
{
	Evaluator eval;
	hand_vector s = { Card(nine,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
}
BOOST_AUTO_TEST_CASE(GR_SF)
{
	Evaluator eval;
	hand_vector s = { Card(nine,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	hand_ptr hand2 = eval.evauluate(s);

	hand1 = eval.evauluate(s);
	s = { Card(nine,spades),Card(eight,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));
	s = { Card(nine,spades),Card(king,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(nine,spades),Card(eight,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));
}
BOOST_AUTO_TEST_CASE(GR_QUADS)
{
	Evaluator eval;
	hand_vector s = { Card(nine,spades),Card(nine,clubs) ,Card(nine,diamonds) ,Card(nine,hearts) ,Card(ace,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(nine,spades),Card(nine,clubs) ,Card(nine,diamonds) ,Card(nine,hearts) ,Card(king,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));

	s = { Card(nine,spades),Card(nine,clubs) ,Card(nine,diamonds) ,Card(nine,hearts) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(ten,spades),Card(ten,clubs) ,Card(ten,diamonds) ,Card(ten,hearts) ,Card(king,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_FULLHOUSE)
{
	Evaluator eval;
	hand_vector s = { Card(nine,spades),Card(nine,clubs) ,Card(nine,diamonds) ,Card(ace,hearts) ,Card(ace,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(ten,spades),Card(ten,clubs) ,Card(ten,diamonds) ,Card(king,hearts) ,Card(king,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand2 > *hand1));

	s = { Card(nine,spades),Card(nine,clubs) ,Card(nine,diamonds) ,Card(ace,hearts) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(nine,spades),Card(nine,clubs) ,Card(nine,diamonds) ,Card(king,hearts) ,Card(king,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));
}
BOOST_AUTO_TEST_CASE(GR_FLUSH)
{
	Evaluator eval;
	hand_vector s = { Card(ace,spades),Card(two,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(ace,spades),Card(eight,spades) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_STRAIGHT)
{
	Evaluator eval;
	hand_vector s = { Card(ace,spades),Card(king,clubs) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(nine,spades),Card(eight,clubs) ,Card(queen,spades) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));
}
BOOST_AUTO_TEST_CASE(GR_TRIPS)
{
	Evaluator eval;
	hand_vector s = { Card(ace,spades),Card(ace,clubs) ,Card(ace,diamonds) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(ace,spades),Card(ace,clubs) ,Card(ace,diamonds) ,Card(nine,spades) ,Card(ten,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));
	BOOST_CHECK(!(*hand2 > *hand1));

	s = { Card(ace,spades),Card(ace,clubs) ,Card(ace,diamonds) ,Card(jack,spades) ,Card(ten,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(king,spades),Card(king,clubs) ,Card(king,diamonds) ,Card(nine,spades) ,Card(ten,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));
}
BOOST_AUTO_TEST_CASE(GR_TWOPAIR)
{
	Evaluator eval;
	hand_vector s = { Card(ace,spades),Card(ace,clubs) ,Card(jack,diamonds) ,Card(jack,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(ace,spades),Card(ace,clubs) ,Card(nine,diamonds) ,Card(nine,spades) ,Card(ten,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));

	s = { Card(ten,spades),Card(ten,clubs) ,Card(jack,diamonds) ,Card(jack,spades) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(ace,spades),Card(ace,clubs) ,Card(nine,diamonds) ,Card(nine,spades) ,Card(ten,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand2 > *hand1));

	s = { Card(ten,spades),Card(ten,clubs) ,Card(jack,diamonds) ,Card(jack,spades) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(ace,spades),Card(ace,clubs) ,Card(two,diamonds) ,Card(two,spades) ,Card(ten,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_PAIR)
{
	Evaluator eval;
	hand_vector s = { Card(ace,spades),Card(ace,clubs) ,Card(jack,diamonds) ,Card(queen,spades) ,Card(ten,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(king,spades),Card(king,clubs) ,Card(nine,diamonds) ,Card(three,spades) ,Card(ten,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));

	s = { Card(three,spades),Card(four,clubs) ,Card(jack,diamonds) ,Card(jack,spades) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(three,spades),Card(four,clubs) ,Card(jack,diamonds) ,Card(jack,spades) ,Card(king,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));

	s = { Card(three,spades),Card(three,clubs) ,Card(king,diamonds) ,Card(jack,spades) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(three,spades),Card(four,clubs) ,Card(jack,diamonds) ,Card(jack,spades) ,Card(king,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand2 > *hand1));

	s = { Card(queen,spades),Card(queen,clubs) ,Card(jack,diamonds) ,Card(eight,spades) ,Card(seven,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(king,spades),Card(king,clubs) ,Card(jack,diamonds) ,Card(eight,spades) ,Card(seven,spades) };
	hand2 = eval.evauluate(s);

	BOOST_CHECK((*hand2 > *hand1));
}
BOOST_AUTO_TEST_CASE(GR_HIGHCARD)
{
	Evaluator eval;

	hand_vector s = { Card(ace,spades),Card(king,clubs) ,Card(jack,diamonds) ,Card(queen,spades) ,Card(four,spades) };
	hand_ptr hand1 = eval.evauluate(s);
	s = { Card(ace,spades),Card(king,clubs) ,Card(jack,diamonds) ,Card(queen,spades) ,Card(five,spades) };
	hand_ptr hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand2 > *hand1));

	s = { Card(three,spades),Card(four,clubs) ,Card(jack,diamonds) ,Card(ten,spades) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(three,spades),Card(four,clubs) ,Card(jack,diamonds) ,Card(ten,spades) ,Card(king,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));

	s = { Card(three,spades),Card(five,clubs) ,Card(king,diamonds) ,Card(jack,spades) ,Card(ace,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(three,spades),Card(four,clubs) ,Card(jack,diamonds) ,Card(ace,spades) ,Card(king,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));

	s = { Card(king,spades),Card(king,clubs) ,Card(king,diamonds) ,Card(four,spades) ,Card(four,spades) };
	hand1 = eval.evauluate(s);
	s = { Card(queen,spades),Card(queen,clubs) ,Card(four,diamonds) ,Card(four,spades) ,Card(ten,spades) };
	hand2 = eval.evauluate(s);
	BOOST_CHECK((*hand1 > *hand2));
}
#endif