#pragma once
#include <string>
#include "hands.hpp"
class Parser
{
public:
	Parser();
	~Parser();

	hand_vector parseHand(std::string input);
};

