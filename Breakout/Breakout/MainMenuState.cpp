#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Enter()
{
	std::cout << "Entering Main Menu State" << std::endl;
}
void MainMenuState::Exit()
{
	std::cout << "Exiting Main Menu State" << std::endl;
}
GameState* MainMenuState::Update()
{
	//if we should transition then transition
	//Otherwise delegate to base class
	return MenuState::Update();
}
GameState* MainMenuState::HandleInput()
{
	//handle paddle movement and all that here
	return MenuState::HandleInput();
}
