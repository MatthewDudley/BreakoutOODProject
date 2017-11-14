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
	TextElement* titleText = new TextElement("Score: " + std::to_string(score));
	titleText->SetX((Renderer::GetInstance().GetScreenWidth() / 2) - (titleText->GetWidth() / 2));
	titleText->SetY((Renderer::GetInstance().GetScreenHeight() / 2) - (titleText->GetHeight() / 2)  - 100);

	textList.push_back(titleText);
}
void ScoreState::Exit()
{

}
GameState* ScoreState::Update()
{
	return GameState::Update();
}