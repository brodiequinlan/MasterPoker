#pragma once

#include "Hand.hpp"
class Parser
{
public:
	Parser();
	~Parser();

	hand_vector parseHand(std::string input);
};

