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
	PhysicsComponent* phsComp = entity->GetPhysicsComponent();
	while (SDL_PollEvent(&e) != 0 && e.key.repeat == 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		//if (e.type == SDL_KEYDOWN)
		//{
		//	switch (e.key.keysym.sym)
		//	{
		//	case SDLK_LEFT:
		//		phsComp->SetVelocity(-phsComp->GetMaxSpeed(), 0);
		//		break;
		//	case SDLK_RIGHT:
		//		phsComp->SetVelocity(phsComp->GetMaxSpeed(), 0);
		//		break;
		//	default:
		//		break;
		//	}
		//}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_LEFT:
			case SDLK_RIGHT:
				phsComp->SetVelocity(0, 0);
				break;
			}
		}
	}

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