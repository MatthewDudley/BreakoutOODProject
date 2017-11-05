#include "MenuState.h"

GameState* MenuState::Update()
{
	//if transition condition is met
		//return Transition(new WhateverState());
	//}
	//If not delegate to base 
	return GameState::Update();
}
GameState* MenuState::HandleInput()
{
	return GameState::HandleInput();
}