#include "GameState.h"
GameState* GameState::Transition(GameState* newState)
{
	this->Exit();
	newState->Enter();
	return newState;
}

GameState* GameState::Update()
{
	return nullptr;
}
GameState* GameState::HandleInput()
{
	return nullptr;
}