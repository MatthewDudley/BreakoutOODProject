#pragma once
#include "GameState.h"
class ScoreState : public GameState
{
public:
	ScoreState(int level, int score);
	~ScoreState();
	virtual void Enter();
	virtual void Exit();
	GameState* Update();
	virtual GameState* APressed() { return nullptr; }
	virtual GameState* SPressed() { return nullptr; }
	virtual GameState* DPressed() { return nullptr; }
private:
	int level;
	int score;
};

