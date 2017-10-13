#pragma once
#include <SDL.h>
class Entity;
//#include "Player.h"
//#include "Actions.h"
class InputManager
{
public:
	InputManager();
	~InputManager();
	bool HandleInput(Entity* entity);
private:
	SDL_Event e;
	const Uint8* currentKeyboardState;
};

