#include "LevelSelectState.h"
#include "TextElement.h"
#include "MainMenuState.h"
#include "Renderer.h"
#include "LevelState.h"

LevelSelectState::LevelSelectState()
{
}


LevelSelectState::~LevelSelectState()
{
}

void LevelSelectState::Enter()
{
	//oh god its a fucking mess look away
	std::cout << "Entering Level Select State" << std::endl;
	TextElement* text = new TextElement("Level Select");
	int x = (Renderer::GetInstance().GetScreenWidth() / 2) - (text->GetWidth() / 2);
	int y = (Renderer::GetInstance().GetScreenHeight() / 2) - (text->GetHeight() / 2);
	text->SetX(x);
	text->SetY(y);



	TextElement* level1Text = new TextElement("Press '1' to play level 1");
	TextElement* level2Text = new TextElement("Press '2' to play level 2");
	TextElement* level3Text = new TextElement("Press '3' to play level 3");
	TextElement* menuText = new TextElement("Press 'a' to return to main menu");
	int commandX = Renderer::GetInstance().GetScreenWidth() / 2;
	int spacing = 50;
	//replayText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + spacing);
	//replayText->SetX(commandX - replayText->GetWidth() / 2);
	menuText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + spacing);
	menuText->SetX(commandX - menuText->GetWidth() / 2);

	level1Text->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 2 * spacing);
	level1Text->SetX(commandX - level1Text->GetWidth() / 2);

	level2Text->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 3 * spacing);
	level2Text->SetX(commandX - level2Text->GetWidth() / 2);
	level3Text->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 4 * spacing);
	level3Text->SetX(commandX - level3Text->GetWidth() / 2);
	//nextText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 2 * spacing);
	//nextText->SetX(commandX - nextText->GetWidth() / 2);
	textList.push_back(menuText);
	textList.push_back(level1Text);
	textList.push_back(level2Text);
	textList.push_back(level3Text);
	textList.push_back(text);
	//textList.push_back(replayText);
	//textList.push_back(nextText);
}
void LevelSelectState::Exit()
{
	std::cout << "Exiting Level Select State" << std::endl;
}
GameState* LevelSelectState::APressed()
{
	return GameState::Transition(new MainMenuState());
}
GameState* LevelSelectState::OnePressed()
{
	return GameState::Transition(new LevelState(1));
}
GameState* LevelSelectState::TwoPressed()
{
	return GameState::Transition(new LevelState(2));
}
GameState* LevelSelectState::ThreePressed()
{
	return GameState::Transition(new LevelState(3));
}