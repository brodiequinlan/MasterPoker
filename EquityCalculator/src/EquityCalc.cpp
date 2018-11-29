
#include <Master.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include <mutex> 
#include <ctime>
#include <vector>

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

hand p1starting;
hand p2starting;


void CalculateResults(int toRun)
{
	Deck* deck = new Deck();
	
	hand p1(p1starting);
	hand p2(p2starting);

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

		p1_ptr = getHand(p1);
		p2_ptr = getHand(p2);
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

		p1.clear();
		p2.clear();

		p1 = hand(p1starting);
		p2 = hand(p2starting);
		deck->reset();
	}
	delete deck;
}

int main()
{
	
	std::string p1h;
	std::string p2h;

	std::cout << "Enter player 1 hand: ";
	std::cin >> p1h;

	std::cout << "Enter player 2 hand: ";
	std::cin >> p2h;


	Parser parser;

	p1starting = parser.parseHand(p1h);
	p2starting = parser.parseHand(p2h);

	int runs = EXHAUSTIVE;

	clock_t tStart = clock();

	std::vector<std::thread> vecOfThreads;
	for (int i = 0; i < 8; ++i)
	{
		vecOfThreads.push_back(std::thread(CalculateResults,EXHAUSTIVE/8));
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

 	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Total Time taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Hand 1 equity: " << h1Equity << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Hand 2 equity: " << h2Equity << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "tie equity: " << tEquity << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;


	system("pause");
}