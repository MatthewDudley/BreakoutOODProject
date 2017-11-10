#pragma once
#include "ScoreState.h"
class LastLevelScoreState :
	public ScoreState
{
public:
	LastLevelScoreState(int level, int score);
	~LastLevelScoreState();
	void Enter();
	void Exit();
	GameState* APressed();
};

