#include "InputManager.h"
#include "Entity.h"
#include "PhysicsComponent.h"
InputManager::InputManager()
{
	currentKeyboardState = SDL_GetKeyboardState(NULL);
}


InputManager::~InputManager()
{
}

bool InputManager::HandleInput(Entity* entity)
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
	*/

	PhysicsComponent* phsComp = entity->GetPhysicsComponent();
	if (phsComp != nullptr)
	{
		if (currentKeyboardState[SDL_SCANCODE_LEFT])
		{
			phsComp->SetVelocity(-phsComp->GetMaxSpeed(), 0);
			//move entity left
			//player->GetInput(PlayerActions::MOVE_LEFT, InputType::HELD);
		}
		if (currentKeyboardState[SDL_SCANCODE_RIGHT])
		{
			phsComp->SetVelocity(phsComp->GetMaxSpeed(), 0);
			//move entity right
			//player->GetInput(PlayerActions::MOVE_RIGHT, InputType::HELD);
		}
	}
	return quit;
}