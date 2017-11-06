#pragma once
#include "GameState.h"
class ExitState : public GameState
{
public:
	ExitState();
	~ExitState();
	void Enter();
	void Exit();
	GameState* Update();
	GameState* HandleInput();
};

