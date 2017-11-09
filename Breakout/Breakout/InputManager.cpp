#include "InputManager.h"
#include "GameState.h"
#include "Entity.h"
#include "PhysicsComponent.h"
InputManager::InputManager()
{
	currentKeyboardState = SDL_GetKeyboardState(NULL);
}


InputManager::~InputManager()
{
}

bool InputManager::HandleInput(GameState* currentState)
{

	//Command pattern code will go here
	bool quit = false;
	//PhysicsComponent* phsComp = entity->GetPhysicsComponent();
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
				currentState->LeftReleased();
				break;
			case SDLK_RIGHT:
				currentState->RightReleased();
				//phsComp->SetVelocity(0, 0);
				break;
			}
		}
	}
	//Instead of just moving the paddle, call the move paddle command

	if (currentKeyboardState[SDL_SCANCODE_LEFT])
	{
		//move entity left
		//phsComp->SetVelocity(-phsComp->GetMaxSpeed(), 0);
		currentState->LeftPressed();
	}
	if (currentKeyboardState[SDL_SCANCODE_RIGHT])
	{
		//move entity right
		//phsComp->SetVelocity(phsComp->GetMaxSpeed(), 0);
		currentState->RightPressed();
	}	

	return quit;
}