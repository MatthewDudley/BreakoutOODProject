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
	std::cout << "Entering Last Score State" << std::endl;
	//TextElement* replayText = new TextElement("Press 'a' to replay level");
	TextElement* menuText = new TextElement("Press 'a' to return to main menu");
	///TextElement* nextText = new TextElement("Press 's' to continue to next level");
	int commandX = Renderer::GetInstance().GetScreenWidth() / 2;
	int spacing = 50;
	//replayText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + spacing);
	//replayText->SetX(commandX - replayText->GetWidth() / 2);
	menuText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 3 * spacing);
	menuText->SetX(commandX - menuText->GetWidth() / 2);
	//nextText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) + 2 * spacing);
	//nextText->SetX(commandX - nextText->GetWidth() / 2);
	textList.push_back(menuText);
	//textList.push_back(replayText);
	//textList.push_back(nextText);
	ScoreState::Enter();
}
void LastLevelScoreState::Exit()
{
	std::cout << "Exiting Score State" << std::endl;
}
GameState* LastLevelScoreState::APressed()
{
	//replay level
	return GameState::Transition(new MainMenuState());
}
//GameState* LastLevelScoreState::SPressed()
//{
//	//next level
//	return GameState::Transition(new LevelState(++level));
//}
//GameState* LastLevelScoreState::DPressed()
//{
//	//go to main menu
//	return GameState::Transition(new MainMenuState());
//}