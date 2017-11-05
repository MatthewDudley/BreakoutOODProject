#pragma once
#include "GameState.h"
class MenuState : public GameState
{
public:
	MenuState() {}
	virtual ~MenuState() {}
	virtual void Enter() {}
	virtual void Exit() {}
	virtual GameState* Update();
	virtual GameState* HandleInput();
};

