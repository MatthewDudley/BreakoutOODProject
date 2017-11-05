#include "LevelState.h"

LevelState::LevelState()
{
}


LevelState::~LevelState()
{
}

void LevelState::Enter()
{
	std::cout << "Entering Level State" << std::endl;
}
void LevelState::Exit()
{
	std::cout << "Exiting Level State" << std::endl;
}
GameState* LevelState::Update()
{
	//if we should transition then transition
	//Otherwise delegate to base class
	return GameState::Update();
}
GameState* LevelState::HandleInput()
{
	//handle paddle movement and all that here
	return GameState::HandleInput();
}