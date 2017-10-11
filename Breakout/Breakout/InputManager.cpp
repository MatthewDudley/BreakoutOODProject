#include "InputManager.h"



InputManager::InputManager()
{
	currentKeyboardState = SDL_GetKeyboardState(NULL);
}


InputManager::~InputManager()
{
}

bool InputManager::HandleInput()//float deltaTime, Player* player)
{
	bool quit = false;
	while (SDL_PollEvent(&e) != 0 && e.key.repeat == 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		/*
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				player->GetInput(PlayerActions::JUMP, InputType::PRESSED);
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				player->GetInput(PlayerActions::JUMP, InputType::RELEASED);
				break;
			case SDLK_LEFT:
				player->GetInput(PlayerActions::MOVE_LEFT, InputType::RELEASED);
				break;
			case SDLK_RIGHT:
				player->GetInput(PlayerActions::MOVE_RIGHT, InputType::RELEASED);
				break;
			}
		}
		*/
	}
	/*
	if (currentKeyboardState[SDL_SCANCODE_UP])
	{
		player->GetInput(PlayerActions::JUMP, InputType::HELD);
	}
	if (currentKeyboardState[SDL_SCANCODE_LEFT])
	{
		player->GetInput(PlayerActions::MOVE_LEFT, InputType::HELD);
	}
	if (currentKeyboardState[SDL_SCANCODE_RIGHT])
	{
		player->GetInput(PlayerActions::MOVE_RIGHT, InputType::HELD);
	}
	*/
	return quit;
}