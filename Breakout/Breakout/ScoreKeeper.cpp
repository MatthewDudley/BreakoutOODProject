#include "ScoreKeeper.h"

#include "ScoreMultipierManager.h"

ScoreKeeper::ScoreKeeper()
{
	scoreIncrementer = 10; 
	multiplierIncrementAmount = .5;
	multiplierManager = new ScoreMultipierManager(this);
}

void ScoreKeeper::Notify()
{
	score += scoreIncrementer * multiplier;
	multiplier += multiplierIncrementAmount;
}
int ScoreKeeper::GetScore()
{
	return score;
}
void ScoreKeeper::WipeScore()
{
	score = 0;
	ResetMultiplier();
}

ScoreMultipierManager* ScoreKeeper::GetMultiplierManager()
{
	return multiplierManager;
}
float ScoreKeeper::GetMultiplier()
{
	return multiplier;
}
ScoreKeeper::~ScoreKeeper()
{
	delete multiplierManager;
}
void ScoreKeeper::ResetMultiplier()
{
	multiplier = 1;
}
