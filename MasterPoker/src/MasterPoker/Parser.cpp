#include "Parser.h"



Parser::Parser()
{
}


Parser::~Parser()
{
}

hand_vector Parser::parseHand(std::string input)
{
	hand_vector _hand;
	cardRank rank;
	cardSuits suit;
	for (int i = 0; i < 4; i+=2)
	{
		if (input[i] == 'a')
		{
			rank = ace;
		}
		else if (input[i] == 'k')
		{
			rank = king;
		}
		else if (input[i] == 'q')
		{
			rank = queen;
		}
		else if (input[i] == 'j')
		{
			rank = jack;
		}
		else if (input[i] == 't')
		{
			rank = ten;
		}
		else if (input[i] == '9')
		{
			rank = nine;
		}
		else if (input[i] == '8')
		{
			rank = eight;
		}
		else if (input[i] == '7')
		{
			rank = seven;
		}
		else if (input[i] == '6')
		{
			rank = six;
		}
		else if (input[i] == '5')
		{
			rank = five;
		}
		else if (input[i] == '4')
		{
			rank = four;
		}
		else if (input[i] == '3')
		{
			rank = three;
		}
		else if (input[i] == '2')
		{
			rank = two;
		}
		if (input[i + 1] == 's')
		{
			suit = spades;
		}
		else if (input[i + 1] == 'c')
		{
			suit = clubs;
		}
		else if (input[i + 1] == 'd')
		{
			suit = diamonds;
		}
		else if (input[i + 1] == 'h')
		{
			suit = hearts;
		}
		_hand.push_back(card(rank, suit));
	}
	return _hand;
}