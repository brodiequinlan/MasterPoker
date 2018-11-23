
#include <Master.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>

// There are other clocks, but this is usually the one you want.
// It corresponds to CLOCK_MONOTONIC at the syscall level.
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using namespace std::literals::chrono_literals;
using std::this_thread::sleep_for;
int main()
{
	clock_t tStart = clock();
	constexpr int EXHAUSTIVE = 1;
	Deck* deck = new Deck();
	card h1c1(king, clubs);
	card h1c2(king, spades);
	card h2c1(queen, diamonds);
	card h2c2(queen, hearts);
	
	double h1Equity = 0.0;
	double h2Equity = 0.0;
	double tEquity = 0.0;
	int h1wins = 0;
	int h2wins = 0;
	int ties = 0;
	int totalRuns = 0;
	hand p1 = { h1c1,h1c2 };
	hand p2 = { h2c1,h2c2 };
	hand_ptr p1_ptr = getHand(p1);
	hand_ptr p2_ptr;

	deck->removeCardF(h1c1);
	deck->removeCardF(h1c2);
	deck->removeCardF(h2c1);
	deck->removeCardF(h2c2);
	for (int i = 0; i < EXHAUSTIVE; ++i)
	{
		time_point<Clock> start = Clock::now();
		deck->shuffle();
		time_point<Clock> end = Clock::now();
		nanoseconds diff = duration_cast<nanoseconds>(end - start);
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << "shuffle took " << diff.count() << " ns" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;


		start = Clock::now();
		for (int i = 0; i < 5; ++i)
		{
			card drawn = deck->draw();

			p1.push_back(drawn);
			p2.push_back(drawn);
		}
		end = Clock::now();
		diff = duration_cast<nanoseconds>(end - start);
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << "loop took " << diff.count() << " ns" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;

		start = Clock::now();
		p1_ptr = getHand(p1);
		end = Clock::now();
		diff = duration_cast<nanoseconds>(end - start);
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << "getHand() took " << diff.count() << " ns" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		p2_ptr = getHand(p2);
		if (*p1_ptr > *p2_ptr)
		{
			h1wins++;
		}
		else if (*p2_ptr > *p1_ptr)
		{
			h2wins++;
		}
		else
		{
			ties++;
		}
		totalRuns++;
		p1.clear();
		p2.clear();

		p1.push_back(h1c1);
		p1.push_back(h1c2);
		p2.push_back(h2c1);
		p2.push_back(h2c2);
		deck->reset();
	}
	h1Equity = (double)h1wins / (double)totalRuns * 100;
	h2Equity = (double)h2wins / (double)totalRuns * 100;
	tEquity = (double)ties / (double)totalRuns * 100;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << h1Equity << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << h2Equity << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << tEquity << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Total Time taken: "<< (double)(clock() - tStart) / CLOCKS_PER_SEC << std::endl;
}