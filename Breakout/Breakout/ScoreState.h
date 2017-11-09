#pragma once
#include "GameState.h"
class ScoreState : public GameState
{
public:
	ScoreState(int level, int score);
	~ScoreState();
	void Enter();
	void Exit();
	GameState* Update();
	GameState* APressed();
	GameState* SPressed();
	GameState* DPressed();
private:
	int level;
	int score;
};

