#include "LastLevelScoreState.h"
#include "TextElement.h"
#include "Renderer.h"
#include "MainMenuState.h"

LastLevelScoreState::LastLevelScoreState(int level, int score) : ScoreState(level, score)
{
}


LastLevelScoreState::~LastLevelScoreState()
{
}
void LastLevelScoreState::Enter()
{
	TextElement* menuText = new TextElement("Press 'a' to return to main menu");
	int commandX = Renderer::GetInstance().GetScreenWidth() / 2;
	int spacing = 50;
	menuText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 3 * spacing);
	menuText->SetX(commandX - menuText->GetWidth() / 2);
	textList.push_back(menuText);
	ScoreState::Enter();
}
void LastLevelScoreState::Exit()
{
}
GameState* LastLevelScoreState::APressed()
{
	return GameState::Transition(new MainMenuState());
}