#include <Master.h>

#include "ISOApp.h"
#include<iostream>
constexpr int EXHAUSTIVE = 100000;
constexpr int HIGH = 40000;
constexpr int LOW = 10000;
constexpr int TEST = 5;

double h1Equity = 0.0;
double h2Equity = 0.0;
double tEquity = 0.0;
int h1wins = 0;
int h2wins = 0;
int ties = 0;
int totalRuns = 0;

std::mutex mtx;

hand_vector p1starting;
hand_vector p2starting;

void CalculateResults(int toRun)
{
	Deck* deck = new Deck();

	hand_vector p1(p1starting);
	hand_vector p2(p2starting);

	for (card c : p1)
	{
		deck->removeCardF(c);
	}
	for (card c : p2)
	{
		deck->removeCardF(c);
	}

	hand_ptr p1_ptr;
	hand_ptr p2_ptr;
	for (int i = 0; i < toRun; ++i)
	{
		deck->shuffle();

		for (int j = 0; j < 5; ++j)
		{
			card drawn = deck->draw();
			p1.push_back(drawn);
			p2.push_back(drawn);
		}

		p1_ptr = evalHand(p1);
		p2_ptr = evalHand(p2);
		if (*p1_ptr > *p2_ptr)
		{
			mtx.lock();
			h1wins++;
			mtx.unlock();
		}
		else if (*p2_ptr > *p1_ptr)
		{
			mtx.lock();
			h2wins++;
			mtx.unlock();
		}
		else
		{
			mtx.lock();
			ties++;
			mtx.unlock();
		}
		mtx.lock();
		totalRuns++;
		mtx.unlock();

		p1_ptr.release();
		p2_ptr.release();

		p1.clear();
		p2.clear();

		p1 = hand_vector(p1starting);
		p2 = hand_vector(p2starting);
		deck->reset();
	}
	delete deck;
}
class EqCalcApp : public ISOApp {
	
	int run() override
	{
		
		Logger::init();

		if (args().size() < 2)
		{
			throw std::string("USAGE: EquityCalculator (hand1{ahad}) (hand2{khkc}) ?(trails{t = test; l = low; h = high; e = exchaustive}{default = e})");
		}

		std::string p1h = args()[0];
		std::string p2h = args()[1];


		Parser parser;

		p1starting = parser.parseHand(p1h);
		p2starting = parser.parseHand(p2h);

		if (contains(p1starting, p2starting[0]) || contains(p1starting, p2starting[1]))
		{
			throw std::invalid_argument("hands contain duplicate cards");
		}
	
		int runs = EXHAUSTIVE;
		if (args().size() > 2)
		{
			auto x = args()[2];
			if (x == std::string("t"))
			{
				runs = TEST;
			}
			else if (x == std::string("h"))
			{
				runs = HIGH;
			}
			else if (x == std::string("l"))
			{
				runs = LOW;
			}
			else if (x == std::string("e"))
			{
				runs = EXHAUSTIVE;
			}
			else
			{
				throw std::invalid_argument(x);
			}
		}

		clock_t tStart = clock();

		std::vector<std::thread> vecOfThreads;
		for (int i = 0; i < 16; ++i)
		{
			vecOfThreads.push_back(std::thread(CalculateResults, runs / 16));
		}
		for (std::thread & th : vecOfThreads)
		{
			// If thread Object is Joinable then Join that thread.
			if (th.joinable())
				th.join();
		}

		h1Equity = (double)h1wins / (double)totalRuns * 100;
		h2Equity = (double)h2wins / (double)totalRuns * 100;
		tEquity = (double)ties / (double)totalRuns * 100;

		Logger::info("------------------------------------------------------------------------------------");
		Logger::info("Total Time taken: " + std::to_string((double)(clock() - tStart) / CLOCKS_PER_SEC));
		Logger::info("------------------------------------------------------------------------------------");
		Logger::info("Hand 1 equity: " + std::to_string(h1Equity));
		Logger::info("------------------------------------------------------------------------------------");
		Logger::info("Hand 2 equity: " + std::to_string(h2Equity));
		Logger::info("------------------------------------------------------------------------------------");
		Logger::info("Tie equity: " + std::to_string(tEquity));
		Logger::info("------------------------------------------------------------------------------------");
	} 
} myApp;