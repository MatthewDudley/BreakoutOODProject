#pragma once
#include <SDL.h>
class GameState;
class Entity;
//#include "Player.h"
//#include "Actions.h"
class InputManager
{
public:
	InputManager();
	~InputManager();
	GameState* HandleInput(GameState* currentState);
private:
	SDL_Event e;
	const Uint8* currentKeyboardState;
};

