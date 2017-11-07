#include "GameState.h"
#include "Renderer.h"
GameState* GameState::Transition(GameState* newState)
{
	this->Exit();
	newState->Enter();
	return newState;
}

GameState* GameState::Update()
{
	//Render the scene
	//Since every game state must render to the screen, the base class handles the rendering
	Renderer::GetInstance().Draw(&entityList, &textList);
	return nullptr;
}
GameState* GameState::HandleInput()
{
	return nullptr;
}