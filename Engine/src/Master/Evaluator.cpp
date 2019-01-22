#include <Master/Evaluator.hpp>
hand_ptr Evaluator::evauluate(const hand_vector &_hand)
{
	if (isRoyalFlush(_hand)) return std::make_unique<Hand>(RoyalFlush());
	else if (isQuads(_hand)) return std::make_unique<Hand>(isQuads(_hand));
	else if (isFullHouse(_hand))return std::make_unique<Hand>(isFullHouse(_hand));
	else if (isStraightFlush(_hand)) return std::make_unique<Hand>(isStraightFlush(_hand));
	else if (isFlush(_hand))return std::make_unique<Hand>(isFlush(_hand));
	else if (isStraight(_hand))return std::make_unique<Hand>(isStraight(_hand));
	else if (isTrips(_hand))return std::make_unique<Hand>(isTrips(_hand));
	else if (isTwoPair(_hand))return std::make_unique<Hand>(isTwoPair(_hand));
	else if (isPair(_hand))return std::make_unique<Hand>(isPair(_hand));
	else return std::make_unique<Hand>(getHighCard(_hand));
}