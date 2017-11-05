#pragma once
#include "MenuState.h"
class MainMenuState : public MenuState
{
public:
	MainMenuState();
	~MainMenuState();
	void Enter();
	void Exit();
	GameState* Update();
	GameState* HandleInput();
};

