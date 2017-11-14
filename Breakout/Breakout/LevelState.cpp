#include <iostream>
#include <fstream>
#include <string>
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
//#include "InputManager.h"
#include "TextElement.h"
#include "EntityFactory.h"
#include "ScoreKeeper.h"
#include "LastLevelScoreState.h"
#include "LevelSelectScoreState.h"
#include "Game.h"

LevelState::LevelState(int levelNumber)
{
	this->levelNumber = levelNumber;
}


LevelState::~LevelState()
{
	//delete inputManager;
	delete scoreKeeper;
}

void LevelState::Enter()
{
	//Set up the level
	scoreKeeper = new ScoreKeeper();
	int screenWidth = Renderer::GetInstance().GetScreenWidth();
	int screenHeight = Renderer::GetInstance().GetScreenHeight();
	currentBallCount = startingBallCount;

	/**Create entities, factory method will be used here**/
	paddle = (Paddle*)EntityFactory::GetInstance().CreateEntity(EntityFactory::EntityType::Paddle, screenWidth / 2, screenHeight - 100);
	
	ball = (Ball*)EntityFactory::GetInstance().CreateEntity(EntityFactory::EntityType::Ball, screenWidth / 2, screenHeight - 200);
	ball->AddObserver(this);
	if (Game::GetInstance().GetGameType() == Game::GameType::RUN)
	{
		ball->GetOnPaddleHit()->AddObserver((Observer*)Game::GetInstance().GetScoreKeeper()->GetMultiplierManager());
	}
	else
	{
		ball->GetOnPaddleHit()->AddObserver((Observer*)scoreKeeper->GetMultiplierManager());
	}
	//Create walls for level boundaries 
	int wallThickness = 25;
	Wall* topWall = new Wall(0, 0, screenWidth, wallThickness);
	topWall->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	topWall->GetSingleImageController()->SetCurrentSpriteRect(0, 0, screenWidth, wallThickness);

	Wall* leftWall= new Wall(0, 0, wallThickness, screenHeight);
	leftWall->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	leftWall->GetSingleImageController()->SetCurrentSpriteRect(0, 0, wallThickness, screenHeight);

	Wall* rightWall= new Wall(screenWidth - wallThickness, 0, wallThickness, screenHeight);
	rightWall->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
	rightWall->GetSingleImageController()->SetCurrentSpriteRect(0, 0, wallThickness, screenHeight);

	//load level by levelNumber
	LoadLevel(levelNumber);

	//Add the rest of the entities to the entity list
	entityList.push_back(paddle);
	entityList.push_back(ball);
	entityList.push_back(topWall);
	entityList.push_back(leftWall);
	entityList.push_back(rightWall);
	ballCounter = new TextElement("Balls: " + std::to_string(currentBallCount), 50, 30);

	if (Game::GetInstance().GetGameType() == Game::GameType::RUN)
	{
		scoreCard = new TextElement("Score: " + std::to_string(Game::GetInstance().GetScoreKeeper()->GetScore()), 50, 50);
		std::string multiplier = std::to_string(Game::GetInstance().GetScoreKeeper()->GetMultiplier());
		multiplier.erase(multiplier.find_last_not_of('0') + 1, std::string::npos);
		multiplierCounter = new TextElement("Multiplier: " + multiplier, 50, 70);

	}
	else
	{
		scoreCard = new TextElement("Score: " + std::to_string(scoreKeeper->GetScore()), 50, 50);
		std::string multiplier = std::to_string(scoreKeeper->GetMultiplier());
		multiplier.erase(multiplier.find_last_not_of('0') + 1, std::string::npos);
		multiplierCounter = new TextElement("Multiplier: " + multiplier, 50, 70);
	}
	textList.push_back(ballCounter);
	textList.push_back(scoreCard);
	textList.push_back(multiplierCounter);
}
void LevelState::LoadLevel(int levelNumber)
{
	int screenWidth = Renderer::GetInstance().GetScreenWidth();
	int screenHeight = Renderer::GetInstance().GetScreenHeight();
	int wallThickness = 25;

	//get filename
	std::ifstream file;
	std::string filename = "Level" + std::to_string(levelNumber) + ".txt";
	file.open("Media\\Levels\\" + filename);

	int brickWidthCount = 0;
	int brickHeightCount = 1;
	std::vector<char> arr;

	char c;
	//open file
	if (file.is_open()) 
	{
		while (file.get(c)) //get each char from the file
		{
			if (c == '#')
			{
				//std::cout << c;
				arr.push_back(c);
				brickWidthCount++;
			}
			else if (c == '_')
			{
				//std::cout << c;
				arr.push_back(c);
				brickWidthCount++;
			}
			else if (c == '\n')
			{
				//std::cout << c;
				brickHeightCount++;
				brickWidthCount = 0;
			}
		}
	}
	else std::cout << "File " << filename << " Could not open" << std::endl;

	//close file
	file.close();

	int brickWidth = 40;
	int brickHeight = 15;
	int screenSpace = screenWidth - (2 * wallThickness);
	int blockSpace = brickWidth * brickWidthCount;
	int whiteSpace = screenSpace - blockSpace;
	int hOffset = (whiteSpace / 2) + wallThickness;
	int vOffset = 100;

	for (int y = 0; y < brickHeightCount; ++y)
	{
		for (int x = 0; x < brickWidthCount; ++x)
		{
			if (arr.at(x + (y*brickWidthCount)) == '#')
			{
				brickCount++;

				Brick* brick = (Brick*)EntityFactory::GetInstance().CreateEntity(EntityFactory::EntityType::Brick, hOffset + x*brickWidth, vOffset + y * brickHeight);
				entityList.push_back(brick);
				brick->AddObserver(scoreKeeper);
				brick->AddObserver(Game::GetInstance().GetScoreKeeper());
			}
		}
	}
}
void LevelState::Exit()
{
}
GameState* LevelState::Update()
{
	if (currentBallCount <= 0)
	{
		return EndLevel(false);
	}
	else if (brickCount <= 0)
	{
		return EndLevel(true);
	}
	//Update the level
	bool quit = false;
	//Destroy the bricks that were hit last frame
	CheckDestroyedBricks();
	//Update the paddle position
	paddle->Update();
	//Update the ball position and check for collisions
	ball->Update(entityList);
	//Delegate update to the base class 

	if (Game::GetInstance().GetGameType() == Game::GameType::RUN)
	{
		scoreCard->SetText("Score: " + std::to_string(Game::GetInstance().GetScoreKeeper()->GetScore()));
		std::string multiplier = std::to_string(Game::GetInstance().GetScoreKeeper()->GetMultiplier());
		multiplier.erase(multiplier.find_last_not_of('0') + 1, std::string::npos);
		multiplierCounter->SetText("Multiplier: " + multiplier);
	}
	else
	{
		scoreCard->SetText("Score: " + std::to_string(scoreKeeper->GetScore()));

		std::string multiplier = std::to_string(scoreKeeper->GetMultiplier());
		multiplier.erase(multiplier.find_last_not_of('0') + 1, std::string::npos);
		multiplierCounter->SetText("Multiplier: " + multiplier);
	}
	ballCounter->SetText("Balls: " + std::to_string(currentBallCount));
	return GameState::Update();
}
void LevelState::stopPaddle()
{
	paddle->GetPhysicsComponent()->SetVelocity(0, 0);
}
GameState * LevelState::LeftPressed()
{
	paddle->GetPhysicsComponent()->SetVelocity(-paddle->GetPhysicsComponent()->GetMaxSpeed(), 0);
	return nullptr;
}
GameState * LevelState::LeftReleased()
{
	stopPaddle();
	return nullptr;
}
GameState * LevelState::RightPressed()
{
	paddle->GetPhysicsComponent()->SetVelocity(paddle->GetPhysicsComponent()->GetMaxSpeed(), 0);
	return nullptr;
}
GameState * LevelState::RightReleased()
{
	stopPaddle();
	return nullptr;
}
GameState* LevelState::APressed()
{
	return EndLevel(true);
}
void LevelState::Notify()
{
	currentBallCount--;
}

GameState* LevelState::EndLevel(bool won)
{
	Game::GameType currentGameType = Game::GetInstance().GetGameType();
	if (currentGameType == Game::GameType::SELECT)
	{
		return GameState::Transition(new LevelSelectScoreState(levelNumber, scoreKeeper->GetScore()));
	}
	else
	{
		if (!won || levelNumber == Game::GetInstance().GetLevelCount())
		{
			return GameState::Transition(new LastLevelScoreState(levelNumber, Game::GetInstance().GetScoreKeeper()->GetScore()));
		}
		else
		{
			return GameState::Transition(new LevelState(++levelNumber));
		}
	}
}


void LevelState::CheckDestroyedBricks()
{
	//Check if a block is destroyed. If so, remove it form the entity list and delete it
	int i = 0;
	while (i < entityList.size())
	{
		if (entityList.at(i)->GetTag() == "brick" && ((Brick*)entityList.at(i))->IsDestroyed())
		{
			delete entityList.at(i);
			entityList.erase(entityList.begin() + i);
			brickCount--;
		}
		else
		{
			++i;
		}
	}
}