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

GameState* InputManager::HandleInput(GameState* currentState)
{
	GameState* newState = nullptr;

	//PhysicsComponent* phsComp = entity->GetPhysicsComponent();
	while (SDL_PollEvent(&e) != 0 && e.key.repeat == 0)
	{
		if (e.type == SDL_QUIT)
		{
			newState = currentState->EscPressed();
			if (newState != nullptr)
			{
				return newState;
			}
		}
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				newState = currentState->EscPressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_a:
				newState = currentState->APressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_s:
				newState = currentState->SPressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_d:
				newState = currentState->DPressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_1:
				newState = currentState->OnePressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_2:
				newState = currentState->TwoPressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_3:
				newState = currentState->ThreePressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_4:
				newState = currentState->FourPressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_5:
				newState = currentState->FivePressed();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			default:
				break;
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_LEFT:
				newState = currentState->LeftReleased();
				if (newState != nullptr)
				{
					return newState;
				}
				break;
			case SDLK_RIGHT:
				newState = currentState->RightReleased();
				if (newState != nullptr)
				{
					return newState;
				}
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
		newState = currentState->LeftPressed();
		if (newState != nullptr)
		{
			return newState;
		}
	}
	if (currentKeyboardState[SDL_SCANCODE_RIGHT])
	{
		//move entity right
		//phsComp->SetVelocity(phsComp->GetMaxSpeed(), 0);
		newState = currentState->RightPressed();
		if (newState != nullptr)
		{
			return newState;
		}
	}	

	return nullptr;
}