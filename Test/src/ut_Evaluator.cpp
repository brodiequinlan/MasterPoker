#include <boost/test/unit_test.hpp>

#include <Master.h>
#include "Phases.hpp"

#if defined(evaluator_tc)
BOOST_AUTO_TEST_CASE(evaluate)
{
	Evaluator eval;
	hand_vector straight = { Card(ace,clubs), Card(king,spades), Card(queen,diamonds), Card(jack,hearts),Card(ten,clubs),Card(two,clubs),Card(three,clubs) };
	hand_vector flush = { Card(ace,clubs),Card(three,clubs) ,Card(queen,clubs), Card(king,clubs),Card(jack,clubs),Card(queen,spades),Card(nine,spades) };
	hand_ptr one = eval.evauluate(straight);
	hand_ptr two = eval.evauluate(flush);
	BOOST_CHECK(one->ranking == 5);
	BOOST_CHECK(two->ranking == 4);

}
#endif