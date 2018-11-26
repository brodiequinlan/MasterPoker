#pragma once
#include <string>
#include "hands.hpp"
class Parser
{
public:
	Parser();
	~Parser();

	hand parseHand(std::string input);
};

