#pragma once
#include "Observer.h"
#include <iostream>
class ScoreKeeper : public Observer
{
public:
	ScoreKeeper();
	void Notify();
	~ScoreKeeper();
private:
	int score = 0;
};

