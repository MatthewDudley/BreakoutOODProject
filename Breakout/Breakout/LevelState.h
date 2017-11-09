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
	LevelState();
	~LevelState();
	void Enter();
	void Exit();
	GameState* Update();
	GameState* HandleInput();
	void stopPaddle();
	virtual GameState* LeftPressed();
	virtual GameState* LeftReleased();
	virtual GameState* RightPressed();
	virtual GameState* RightReleased();
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
};