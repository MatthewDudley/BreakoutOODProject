#pragma once
#include <SDL.h>
#include <stdio.h>
//#include "Player.h"
//#include "Actions.h"
class InputManager
{
public:
	InputManager();
	~InputManager();
	bool HandleInput();//float deltaTime, Player* player);
private:
	SDL_Event e;
	const Uint8* currentKeyboardState;
};

