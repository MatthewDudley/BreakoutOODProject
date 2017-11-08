#include "ScoreKeeper.h"



ScoreKeeper::ScoreKeeper()
{
	std::cout << "Score: " << score << std::endl;
}

void ScoreKeeper::Notify()
{
	score += 10;
	std::cout << "Score: " << score << std::endl;
}

ScoreKeeper::~ScoreKeeper()
{
}
