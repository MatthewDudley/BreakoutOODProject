#pragma once
#include "GameState.h"
#include <vector>
#include "Observer.h"
class Entity;
class Paddle;
class Ball;
class InputManager;
class ScoreKeeper;
class LevelState : public GameState, public Observer
{
public:
	LevelState(int levelNumber);
	~LevelState();
	void Enter();
	void Exit();
	GameState* Update();
	void stopPaddle();
	GameState* LeftPressed();
	GameState* LeftReleased();
	GameState* RightPressed();
	GameState* RightReleased();
	void Notify();
private:
	void CheckDestroyedBricks();
	//std::vector<Entity*> entityList;
	Ball* ball;
	Paddle* paddle;
	//InputManager* inputManager;
	ScoreKeeper* scoreKeeper;
	TextElement* scoreCard;
	TextElement* ballCounter;
	int startingBallCount = 3;
	int currentBallCount;
	int levelNumber;
};