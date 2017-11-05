#pragma once
#include "GameState.h"
class LevelState : public GameState
{
public:
	LevelState();
	~LevelState();
	void Enter();
	void Exit();
	GameState* Update();
	GameState* HandleInput();
};