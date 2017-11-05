#include "GameState.h"
#include "Time.h"
GameState* GameState::Transition(GameState* newState)
{
	this->Exit();
	newState->Enter();
	return newState;
}

GameState* GameState::Update()
{
	Time::CalculateDeltaTime();
	return nullptr;
}
GameState* GameState::HandleInput()
{
	return nullptr;
}