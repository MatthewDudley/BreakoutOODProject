#pragma once
#include <iostream>
class GameState
{
public:
	virtual ~GameState() {}
	virtual void Enter() {}
	virtual void Exit() {}
	virtual GameState* Update();
	virtual GameState* HandleInput();
	GameState* Transition(GameState* newState);
};

