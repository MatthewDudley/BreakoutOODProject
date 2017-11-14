#pragma once
#include "GameState.h"
class LevelSelectState : public GameState
{
public:
	LevelSelectState();
	~LevelSelectState();
	void Enter();
	void Exit();
	GameState* APressed();
	GameState* OnePressed();
	GameState* TwoPressed();
	GameState* ThreePressed();
	GameState* FourPressed();
	GameState* FivePressed();
};

