#include "ScoreKeeper.h"



ScoreKeeper::ScoreKeeper()
{
}

void ScoreKeeper::Notify()
{
	score += 10;
}
int ScoreKeeper::GetScore()
{
	return score;
}
void ScoreKeeper::WipeScore()
{
	score = 0;
}
ScoreKeeper::~ScoreKeeper()
{
}
