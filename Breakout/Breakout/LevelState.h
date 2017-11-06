#pragma once
#include "GameState.h"
#include <vector>

class Entity;
class Paddle;
class Ball;
class InputManager;
class LevelState : public GameState
{
public:
	LevelState();
	~LevelState();
	void Enter();
	void Exit();
	GameState* Update();
	GameState* HandleInput();
private:
	void CheckDestroyedBricks();
	//std::vector<Entity*> entityList;
	Ball* ball;
	Paddle* paddle;
	InputManager* inputManager;
};