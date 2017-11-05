#pragma once
#include "GameState.h"
#include <vector>

class Entity;
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
	std::vector<Entity*> entityList;
};