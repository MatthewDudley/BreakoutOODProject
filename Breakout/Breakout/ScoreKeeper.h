#pragma once
#include "Observer.h"
#include <iostream>
class ScoreKeeper : public Observer
{
public:
	ScoreKeeper();
	void Notify();
	int GetScore();
	~ScoreKeeper();
private:
	int score = 0;
};

