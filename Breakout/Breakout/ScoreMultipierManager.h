#pragma once
#include "Observer.h"
class ScoreKeeper;
class ScoreMultipierManager : public Observer
{
public:
	ScoreMultipierManager(ScoreKeeper* scoreKeeper);
	~ScoreMultipierManager();
	void Notify();
private:
	ScoreKeeper* scoreKeeper;
};

