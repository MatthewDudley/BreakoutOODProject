#include "GameState.h"
#include "Renderer.h"

GameState::~GameState()
{
	//Delete all elements of the entity list
	for (int i = 0; i < entityList.size(); ++i)
	{
		delete entityList.at(i);
	}
	//Delete all elements in text list
	for (int i = 0; i < textList.size(); ++i)
	{
		delete textList.at(i);
	}
}
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

GameState* GameState::LeftPressed()
{
	return nullptr;
}
GameState * GameState::LeftReleased()
{
	return nullptr;
}
GameState* GameState::RightPressed()
{
	return nullptr;
}
GameState * GameState::RightReleased()
{
	return nullptr;
}
GameState* GameState::EscPressed()
{
	return nullptr;
}
