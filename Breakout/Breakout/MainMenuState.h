#pragma once
#include "GameState.h"
class MainMenuState : public GameState
{
public:
	MainMenuState();
	~MainMenuState();
	void Enter();
	void Exit();
	GameState* Update();
	GameState* APressed();
	GameState* SPressed();
};

