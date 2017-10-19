#include "Game.h"
#include "Renderer.h"
#include "InputManager.h"
#include "MediaManager.h"
#include "VisualComponent.h"
#include "SingleImageController.h"
#include "Entity.h"
#include "Paddle.h"
#include "Time.h"
#include "PhysicsComponent.h"
//#include "Animation.h"

Game::Game()
{
	screenWidth = 800;
	screenHeight = 601;
	levelWidth = 1000;
	levelHeight = 1001;

	renderer = new Renderer(screenWidth, screenHeight, false);
	mediaManager = new MediaManager();
	inputManager = new InputManager();
}


Game::~Game()
{
	delete renderer;
	delete mediaManager;
	delete inputManager;
}

void Game::Start()
{
	if (Initialize())
	{
		bool quit = false;
		Paddle paddle(250, 250);
		paddle.GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
		paddle.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 100);
		paddle.GetPhysicsComponent()->SetMaxSpeed(100.0f);

		std::vector<Entity*> entityList;
		entityList.push_back(&paddle);
		/*
		Player player(350, 150, 18, 26, -9.0f, -12.0f);
		player.GetAnimationController()->SetTexture(mediaManager->GetTexture(0));
		player.GetAnimationController()->SetAnimationMap(mediaManager->GetPlayerAnimations());
		player.Initialize();
		
		BlockTest block(350, 345, 100, 100, -50.0f, -50.0f, false);
		block.GetVisualComponent()->SetTexture(mediaManager->GetTexture(1));
		block.GetSingleImageController()->SetCurrentSpriteRect(100, 0, 100, 100);
		*/

		Uint32 lastFrameTime = 0;
		Uint32 currentFrameTime = 0;
		float deltaTime = 0.0f;
		//renderer->Draw(&entityList, &camera);
		currentFrameTime = SDL_GetTicks();
		while (quit == false)
		{
			lastFrameTime = currentFrameTime;
			currentFrameTime = SDL_GetTicks();
			Time::CalculateDeltaTime(lastFrameTime, currentFrameTime);
			//deltaTime = (float)(currentFrameTime - lastFrameTime) / 1000;
			//player.GetTiming(lastFrameTime, currentFrameTime, deltaTime);
			quit = inputManager->HandleInput(&paddle);//deltaTime, &player);
			//player.Update(entityList);
			//camera.Reset();
			paddle.Update();
			renderer->Draw(&entityList);// , &camera);
			//SDL_Delay(30);
		}
	}
}

bool Game::Initialize()
{
	if (renderer->Initialize() == true)
	{
		mediaManager->CreateTexture("Media/Sprites/block1.png", renderer->GetRenderer());
		/*
		mediaManager->CreateTexture("Media/Sprites/megamanx.png", renderer->GetRenderer());
		//mediaManager->CreateTexture("Media/Sprites/megamanxidlerun.png", renderer->GetRenderer());
		//mediaManager->CreateTexture("Media/Sprites/runningplayertransparencytest.png", renderer->GetRenderer());
		mediaManager->CreateTexture("Media/Sprites/blocktypes.png", renderer->GetRenderer());
		mediaManager->CreateTexture("Media/Sprites/player1.png", renderer->GetRenderer());
		mediaManager->CreateTexture("Media/Sprites/block1.png", renderer->GetRenderer());
		mediaManager->GeneratePlayerAnimations();
		*/
		return true;
	}
	else
	{
		return false;
	}
}