#pragma once
#include "GameState.h"
class LevelSelectState :
	public GameState
{
public:
	LevelSelectState();
	~LevelSelectState();
	void Enter();
	void Exit();
	virtual GameState* APressed();
	virtual GameState* OnePressed();
	virtual GameState* TwoPressed();
	virtual GameState* ThreePressed();
};

