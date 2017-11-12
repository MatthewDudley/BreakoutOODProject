#pragma once
#include "ScoreState.h"
class LevelSelectScoreState : public ScoreState
{
public:
	LevelSelectScoreState(int level, int score);
	~LevelSelectScoreState();
	void Enter();
	void Exit();
	GameState* APressed();
	GameState* SPressed();
};