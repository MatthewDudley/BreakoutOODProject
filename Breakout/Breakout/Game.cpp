#include "Game.h"
#include "Renderer.h"
#include "MediaManager.h"
#include "Time.h"
#include "GameState.h"
#include "LevelState.h"
#include "InputManager.h"
#include "MainMenuState.h"

Game::Game()
{
	screenWidth = 800;
	screenHeight = 600;

	currentState = new MainMenuState();//LevelState();
	inputManager = new InputManager();
}


Game::~Game()
{
	delete currentState;
}

void Game::Start()
{
	if (Initialize())
	{
		//Enters the first state
		currentState->Enter();
		bool quit = false;
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
		//MediaManager::GetInstance().LoadFont("Media/Fonts/TimesNewRoman.ttf", 18);
		MediaManager::GetInstance().LoadFont("Media/Fonts/FippsRegular.ttf", 16);

		/*
		mediaManager->GeneratePlayerAnimations();
		*/
		return true;
	}
	else
	{
		return false;
	}
}