#include "ExitState.h"
#include "TextElement.h"
#include "Renderer.h"
#include "Game.h"
ExitState::ExitState()
{
}


ExitState::~ExitState()
{
}

void ExitState::Enter()
{
	Game::GetInstance().QuitGame();
	TextElement* text = new TextElement("Goodbye");
	int x = (Renderer::GetInstance().GetScreenWidth() / 2) - (text->GetWidth()/2);
	int y = (Renderer::GetInstance().GetScreenHeight() / 2) - (text->GetHeight()/2);
	text->SetX(x);
	text->SetY(y);
	textList.push_back(text);
}
void ExitState::Exit()
{
}
GameState* ExitState::Update()
{
	return GameState::Update();
}