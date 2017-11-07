#include "ExitState.h"



ExitState::ExitState()
{
}


ExitState::~ExitState()
{
}

void ExitState::Enter()
{
	std::cout << "Entering Exit State" << std::endl;
	//textList.push_back(new TextElement(50, 50, "Hello World!"));
}
void ExitState::Exit()
{
	std::cout << "Exiting... exit state? How?" << std::endl;
}
GameState* ExitState::Update()
{
	std::cout << "Close the console window to close the game" << std::endl;
	return nullptr;
}
GameState* ExitState::HandleInput()
{
	return nullptr;
}