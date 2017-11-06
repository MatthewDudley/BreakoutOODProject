#include "LevelState.h"
#include "Entity.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "SingleImageController.h"
#include "PhysicsComponent.h"
#include "Renderer.h"
#include "MediaManager.h"
#include "InputManager.h"
LevelState::LevelState()
{
}


LevelState::~LevelState()
{
	delete paddle;
	delete ball;
	delete inputManager;
}

void LevelState::Enter()
{
	inputManager = new InputManager();
	std::cout << "Entering Level State" << std::endl;
	int screenWidth = Renderer::GetInstance().GetScreenWidth();
	int screenHeight = Renderer::GetInstance().GetScreenHeight();
	paddle = new Paddle(screenWidth / 2 - 50, screenHeight - 100, 100, 15, 0, 0);
	paddle->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	paddle->GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 15);
	paddle->GetPhysicsComponent()->SetMaxSpeed(200.0f);
	paddle->SetBounds(25, screenWidth - 25);
	ball = new Ball(screenWidth / 2, screenHeight - 125, 10, 10, 0, 0, 200, 5, 400);
	ball->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	ball->GetSingleImageController()->SetCurrentSpriteRect(0, 0, 10, 10);
	ball->GetPhysicsComponent()->SetMaxSpeed(100.0f);
	ball->GetPhysicsComponent()->SetVelocity(0, 180);

	int wallThickness = 25;
	Wall* topWall = new Wall(0, 0, screenWidth, wallThickness);
	topWall->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	topWall->GetSingleImageController()->SetCurrentSpriteRect(0, 0, screenWidth, wallThickness);

	Wall* bottomWall = new Wall(0, screenHeight - wallThickness, screenWidth, wallThickness);
	bottomWall->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	bottomWall->GetSingleImageController()->SetCurrentSpriteRect(0, 0, screenWidth, wallThickness);

	Wall* leftWall= new Wall(0, 0, wallThickness, screenHeight);
	leftWall->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	leftWall->GetSingleImageController()->SetCurrentSpriteRect(0, 0, wallThickness, screenHeight);

	Wall* rightWall= new Wall(screenWidth - wallThickness, 0, wallThickness, screenHeight);
	rightWall->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	rightWall->GetSingleImageController()->SetCurrentSpriteRect(0, 0, wallThickness, screenHeight);

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
			brick->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
			brick->GetSingleImageController()->SetCurrentSpriteRect(0, 0, brickWidth, brickHeight);
			entityList.push_back(brick);
		}
	}
	entityList.push_back(paddle);
	entityList.push_back(ball);
	entityList.push_back(topWall);
	entityList.push_back(bottomWall);
	entityList.push_back(leftWall);
	entityList.push_back(rightWall);
}
void LevelState::Exit()
{
	std::cout << "Exiting Level State" << std::endl;
}
GameState* LevelState::Update()
{
	bool quit = false;
	CheckDestroyedBricks();
	quit = inputManager->HandleInput(paddle);
	if (quit)
	{
		//quit the game
	}
	paddle->Update();
	ball->Update(entityList);
	Renderer::GetInstance().Draw(&entityList);
	return GameState::Update();
}
GameState* LevelState::HandleInput()
{
	//handle paddle movement and all that here
	return GameState::HandleInput();
}

void LevelState::CheckDestroyedBricks()
{
	int i = 0;
	while (i < entityList.size())
	{
		if (entityList.at(i)->GetTag() == "brick" && ((Brick*)entityList.at(i))->IsDestroyed())
		{
			entityList.erase(entityList.begin() + i);
		}
		else
		{
			++i;
		}
	}
}