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
#include "Ball.h"
#include "Wall.h"
#include "Brick.h"
#include "EntityFactory.h"

Game::Game()
{
	screenWidth = 800;
	screenHeight = 601;

	renderer = &Renderer::GetInstance();//new Renderer(screenWidth, screenHeight, false);
	mediaManager = &MediaManager::GetInstance();//new MediaManager();
	inputManager = new InputManager();
}


Game::~Game()
{
	//delete renderer;
	//delete mediaManager;
	delete inputManager;
}

void Game::Start()
{
	if (Initialize())
	{
		bool quit = false;

		//Entities are instantiated here
		
		//Factory takes in an EntityType, x coord, y coord and creates the EntityType

		Entity* paddleTest = EntityFactory::GetInstance().CreateEntity(EntityFactory::EntityType::Paddle, (screenWidth / 2 - 50), (screenHeight - 100));
		
		Entity* ballTest = EntityFactory::GetInstance().CreateEntity(EntityFactory::EntityType::Ball, (screenWidth / 2), (screenHeight - 125));

		//Bricks based on level and loop to create them
		//Entity* brickTest = EntityFactory::GetInstance().CreateEntity(EntityFactory::EntityType::Brick (), ());

		Paddle paddle(screenWidth/2 - 50, screenHeight - 100, 100, 15, 0, 0);
		paddle.GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
		paddle.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 15);
		paddle.GetPhysicsComponent()->SetMaxSpeed(200.0f);
		paddle.SetBounds(25, screenWidth - 25);

		Ball ball(screenWidth/2, screenHeight - 125, 10, 10, 0, 0, 200, 5, 400);
		ball.GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
		ball.GetSingleImageController()->SetCurrentSpriteRect(0, 0, 10, 10);
		ball.GetPhysicsComponent()->SetMaxSpeed(100.0f);
		ball.GetPhysicsComponent()->SetVelocity(0,180);

		int wallThickness = 25;
		Wall topWall(0, 0, screenWidth, wallThickness);
		topWall.GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
		topWall.GetSingleImageController()->SetCurrentSpriteRect(0, 0, screenWidth, wallThickness);

		Wall bottomWall(0, screenHeight - wallThickness, screenWidth, wallThickness);
		bottomWall.GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
		bottomWall.GetSingleImageController()->SetCurrentSpriteRect(0, 0, screenWidth, wallThickness);

		Wall leftWall(0, 0, wallThickness, screenHeight);
		leftWall.GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
		leftWall.GetSingleImageController()->SetCurrentSpriteRect(0, 0, wallThickness, screenHeight);

		Wall rightWall(screenWidth - wallThickness, 0, wallThickness, screenHeight);
		rightWall.GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
		rightWall.GetSingleImageController()->SetCurrentSpriteRect(0, 0, wallThickness, screenHeight);


		std::vector<Entity*> entityList;
		int brickWidthCount = 16;
		int brickHeightCount = 10;
		int brickWidth = 40;
		int brickHeight = 15;
		int screenSpace = screenWidth - (2 * wallThickness);
		int blockSpace = brickWidth * brickWidthCount;
		int whiteSpace = screenSpace - blockSpace;
		int hOffset = (whiteSpace / 2) + wallThickness;
		int vOffset = 100;
		for (int i = 0; i < brickWidthCount; ++i)
		{
			for (int j = 0; j < brickHeightCount; ++j)
			{
				Brick* brick = new Brick(hOffset + i*brickWidth, vOffset + j * brickHeight, brickWidth, brickHeight);
				brick->GetSingleImageController()->SetTexture(mediaManager->GetTexture(0));
				brick->GetSingleImageController()->SetCurrentSpriteRect(0, 0, brickWidth, brickHeight);
				entityList.push_back(brick);
			}
		}
		entityList.push_back(&paddle);
		entityList.push_back(&ball);
		entityList.push_back(&topWall);
		entityList.push_back(&bottomWall);
		entityList.push_back(&leftWall);
		entityList.push_back(&rightWall);
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
			CheckDestroyedBricks(&entityList);
			quit = inputManager->HandleInput(&paddle);//deltaTime, &player);
			//player.Update(entityList);
			//camera.Reset();
			paddle.Update();
			ball.Update(entityList);
			renderer->Draw(&entityList);// , &camera);
			//SDL_Delay(30);
		}
	}
}

void Game::CheckDestroyedBricks(std::vector<Entity*>* entityList)
{
	int i = 0;
	while (i < entityList->size())
	{
		if (entityList->at(i)->GetTag() == "brick" && ((Brick*)entityList->at(i))->IsDestroyed())
		{
			entityList->erase(entityList->begin() + i);
		}
		else
		{
			++i;
		}
	}
}

bool Game::Initialize()
{
	if (renderer->Initialize(screenWidth, screenHeight, false) == true)
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