#include "ScoreMultipierManager.h"
#include "ScoreKeeper.h"
#include <iostream>

ScoreMultipierManager::ScoreMultipierManager(ScoreKeeper* scoreKeeper)
{
	this->scoreKeeper = scoreKeeper;
}


ScoreMultipierManager::~ScoreMultipierManager()
{
}

void ScoreMultipierManager::Notify()
{
	scoreKeeper->ResetMultiplier();
}