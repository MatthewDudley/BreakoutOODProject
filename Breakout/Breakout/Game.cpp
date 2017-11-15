#include "Game.h"
#include "Renderer.h"
#include "MediaManager.h"
#include "Time.h"
#include "GameState.h"
#include "LevelState.h"
#include "InputManager.h"
#include "MainMenuState.h"
#include "ScoreKeeper.h"
Game::Game()
{
	screenWidth = 800;
	screenHeight = 600;
	levelCount = 5;
	currentGameType == Game::GameType::RUN;
	currentState = new MainMenuState();
	inputManager = new InputManager();
	scoreKeeper = new ScoreKeeper();

}


Game::~Game()
{
	delete currentState;
	delete scoreKeeper;
	delete inputManager;
}

void Game::Start()
{
	if (Initialize())
	{
		//Enters the first state
		currentState->Enter();
		float deltaTime = 0.0f;
		Uint32 lastFrameTime = 0;
		Uint32 currentFrameTime = SDL_GetTicks();
		while (!quit)
		{
			lastFrameTime = currentFrameTime;
			currentFrameTime = SDL_GetTicks();
			Time::CalculateDeltaTime(lastFrameTime, currentFrameTime);

			//Updates the current state
			GameState* newState = inputManager->HandleInput(currentState);
			if (newState != nullptr)
			{
				//If the state needs to change, change it
				delete currentState;
				currentState = newState;
			}
			newState = currentState->Update();
			if (newState != nullptr)
			{
				delete currentState;
				currentState = newState;
			}
		}
	}
}

bool Game::Initialize()
{
	if (Renderer::GetInstance().Initialize(screenWidth, screenHeight, false) == true)
	{
		MediaManager::GetInstance().CreateTexture("Media/Sprites/block1.png", Renderer::GetInstance().GetRenderer());
		MediaManager::GetInstance().CreateTexture("Media/Sprites/breakoutsprites1.png", Renderer::GetInstance().GetRenderer());
		MediaManager::GetInstance().CreateTexture("Media/Sprites/VerticalWall.png", Renderer::GetInstance().GetRenderer());
		MediaManager::GetInstance().CreateTexture("Media/Sprites/HorizontalWall.png", Renderer::GetInstance().GetRenderer());
		MediaManager::GetInstance().LoadFont("Media/Fonts/FippsRegular.ttf", 16);
		return true;
	}
	else
	{
		return false;
	}
}
void Game::SetGameType(Game::GameType type)
{
	if (type == GameType::RUN)
	{
		scoreKeeper->WipeScore();
	}
	currentGameType = type;
}
Game::GameType Game::GetGameType()
{
	return currentGameType;
}
Game& Game::GetInstance()
{
	//No need to check if the instance exists, C++ won't create another static instance
	//Also thread safe by default, C++ automatically locks on instance creation
	static Game instance;
	return instance;
}

ScoreKeeper* Game::GetScoreKeeper()
{
	return scoreKeeper;
}
int Game::GetLevelCount()
{
	return levelCount;
}
void Game::QuitGame()
{
	quit = true;
}