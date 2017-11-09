#pragma once
#include <SDL.h>
#include <iostream>

class GameState;
class InputManager;
/*
#include "Entity.h"
#include "Player.h"
#include "BlockTest.h"
#include <vector>
#include "Texture.h"
#include "MediaManager.h"
#include "Camera.h"
#include "AnimationNames.h"
*/
class Game
{
public:
	Game();
	~Game();
	void Start();
private:
	bool Initialize();
	int screenWidth;
	int screenHeight;
	InputManager* inputManager;
	//void CheckDestroyedBricks(std::vector<Entity*>* entityList);

	//Renderer* renderer;
	//MediaManager* mediaManager;
	//InputManager* inputManager;

	GameState* currentState;

};

