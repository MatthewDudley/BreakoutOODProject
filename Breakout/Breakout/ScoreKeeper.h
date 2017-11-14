#pragma once
#include "Observer.h"
#include <iostream>
class ScoreMultipierManager;
class ScoreKeeper : public Observer
{
public:
	ScoreKeeper();
	void Notify();
	int GetScore();
	void WipeScore();
	ScoreMultipierManager* GetMultiplierManager();
	void ResetMultiplier();
	float GetMultiplier();
	~ScoreKeeper();
private:
	int score = 0;
	int scoreIncrementer;
	float multiplier = 1;
	float multiplierIncrementAmount;
	ScoreMultipierManager* multiplierManager;
};

