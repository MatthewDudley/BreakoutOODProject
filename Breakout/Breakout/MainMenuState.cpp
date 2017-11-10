#include "MainMenuState.h"
#include "LevelState.h"
#include "ExitState.h"
#include "TextElement.h"
#include "Renderer.h"
#include "LevelSelectState.h"
MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Enter()
{
	std::cout << "Entering Main Menu State" << std::endl;
	TextElement* playText = new TextElement("Press 'a' to play");
	TextElement* selectText = new TextElement("Press 's' to select level");
	TextElement* exitText = new TextElement("Press 'd' to exit");
	TextElement* menuText = new TextElement("Breakout Clone");
	menuText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (menuText->GetWidth() / 2));
	menuText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) - (menuText->GetHeight() / 2));

	int commandY = Renderer::GetInstance().GetScreenHeight() - 200;
	int spacing = 100;
	playText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (playText->GetWidth()) - spacing/2);
	playText->SetY(commandY);
	exitText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (exitText->GetWidth() / 2));
	exitText->SetY(commandY + 50);

	selectText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) + spacing / 2);
	selectText->SetY(commandY);
	textList.push_back(menuText);
	textList.push_back(selectText);
	textList.push_back(exitText);
	textList.push_back(playText);
}
void MainMenuState::Exit()
{
	std::cout << "Exiting Main Menu State" << std::endl;
}
GameState* MainMenuState::Update()
{
	//if we should transition then transition
	//Otherwise delegate to base class
	return GameState::Update();
}
GameState* MainMenuState::APressed()
{
	//continue to play level
	return GameState::Transition(new LevelState(1));
}
GameState* MainMenuState::SPressed()
{
	//exit
	return GameState::Transition(new LevelSelectState());
}
GameState* MainMenuState::DPressed()
{
	return GameState::Transition(new ExitState());
}
