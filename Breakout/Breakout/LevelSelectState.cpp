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
	TextElement* text = new TextElement("Level Select");
	int x = (Renderer::GetInstance().GetScreenWidth() / 2) - (text->GetWidth() / 2);
	int y = (Renderer::GetInstance().GetScreenHeight() / 2) - (text->GetHeight() / 2) - 100;
	text->SetX(x);
	text->SetY(y);



	TextElement* level1Text = new TextElement("Press '1' to play level 1");
	TextElement* level2Text = new TextElement("Press '2' to play level 2");
	TextElement* level3Text = new TextElement("Press '3' to play level 3");
	TextElement* level4Text = new TextElement("Press '4' to play level 4");
	TextElement* level5Text = new TextElement("Press '5' to play level 5");
	TextElement* menuText = new TextElement("Press 'a' to return to main menu");
	int commandX = Renderer::GetInstance().GetScreenWidth() / 2;
	int spacing = 50;
	int starting = (Renderer::GetInstance().GetScreenHeight() / 2) - 80;

	menuText->SetY(starting + spacing);
	menuText->SetX(commandX - menuText->GetWidth() / 2);

	level1Text->SetY(starting + 2 * spacing);
	level1Text->SetX(commandX - level1Text->GetWidth() / 2);

	level2Text->SetY(starting + 3 * spacing);
	level2Text->SetX(commandX - level2Text->GetWidth() / 2);
	level3Text->SetY(starting + 4 * spacing);
	level3Text->SetX(commandX - level3Text->GetWidth() / 2);
	level4Text->SetY(starting + 5 * spacing);
	level4Text->SetX(commandX - level4Text->GetWidth() / 2);
	level5Text->SetY(starting + 6 * spacing);
	level5Text->SetX(commandX - level5Text->GetWidth() / 2);

	textList.push_back(menuText);
	textList.push_back(level1Text);
	textList.push_back(level2Text);
	textList.push_back(level3Text);
	textList.push_back(level4Text);
	textList.push_back(level5Text);
	textList.push_back(text);
}
void LevelSelectState::Exit()
{
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
GameState* LevelSelectState::FourPressed()
{
	return GameState::Transition(new LevelState(4));
}
GameState* LevelSelectState::FivePressed()
{
	return GameState::Transition(new LevelState(5));
}