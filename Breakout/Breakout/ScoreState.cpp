#include "ScoreState.h"
#include "LevelState.h"
#include "MainMenuState.h"
#include "TextElement.h"
#include "Renderer.h"

ScoreState::ScoreState(int level, int score)
{
	this->level = level;
	this->score = score;
}


ScoreState::~ScoreState()
{
}

void ScoreState::Enter()
{
	std::cout << "Entering Score State" << std::endl;
	TextElement* replayText = new TextElement("Press 'a' to replay level");
	TextElement* menuText = new TextElement("Press 'd' to return to main menu");
	TextElement* nextText = new TextElement("Press 's' to continue to next level");
	TextElement* titleText = new TextElement("Score: " + std::to_string(score));
	titleText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (titleText->GetWidth() / 2));
	titleText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) - (titleText->GetHeight() / 2)  - 100);

	int commandX = Renderer::GetInstance().GetScreenWidth()/2;
	int spacing = 50;
	replayText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + spacing);
	replayText->SetX(commandX - replayText->GetWidth() / 2);
	menuText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 3 * spacing);
	menuText->SetX(commandX - menuText->GetWidth()/2);
	nextText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 2 * spacing);
	nextText->SetX(commandX - nextText->GetWidth() / 2);
	textList.push_back(menuText);
	textList.push_back(replayText);
	textList.push_back(nextText);
	textList.push_back(titleText);
}
void ScoreState::Exit()
{
	std::cout << "Exiting Score State" << std::endl;
}
GameState* ScoreState::Update()
{
	//if we should transition then transition
	//Otherwise delegate to base class
	return GameState::Update();
}
GameState* ScoreState::APressed()
{
	//replay level
	return GameState::Transition(new LevelState(level));
}
GameState* ScoreState::SPressed()
{
	//next level
	return GameState::Transition(new LevelState(++level));
}
GameState* ScoreState::DPressed()
{
	//go to main menu
	return GameState::Transition(new MainMenuState());
}