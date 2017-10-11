#pragma once
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "Renderer.h"
#include "InputManager.h"
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
	int levelWidth;
	int levelHeight;

	Renderer* renderer;
	//MediaManager* mediaManager;
	InputManager* inputManager;

};

