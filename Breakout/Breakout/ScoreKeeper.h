#pragma once
#include "Observer.h"
#include <iostream>
class ScoreKeeper : public Observer
{
public:
	ScoreKeeper();
	void Notify();
	int GetScore();
	void WipeScore();
	~ScoreKeeper();
private:
	int score = 0;
};

