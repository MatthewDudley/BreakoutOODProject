#include "Renderer.h"
#include "Entity.h"
#include "VisualComponent.h"
#include "Collider.h"
#include "math.h"
Renderer::Renderer(int screenWidth, int screenHeight, bool debug)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->debug = debug;
}


Renderer::~Renderer()
{
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
	sdlRenderer = NULL;
	sdlWindow = NULL;
	IMG_Quit();
	SDL_Quit();
}

void Renderer::Render(Entity* entity)//, Camera* camera)
{
	//entity->GetTexture()->Render((int)entity->GetPosX() - (int)camera->GetPosX(), (int)entity->GetPosY() - (int)camera->GetPosY(), sdlRenderer);
	//entity->GetTexture()->Render((int)entity->GetCollider()->GetPosX() - (int)camera->GetPosX() + entity->GetCollider()->GetWidth()/2 , (int)entity->GetCollider()->GetPosY() - (int)camera->GetPosY() + entity->GetCollider()->GetHeight() / 2, sdlRenderer, entity->GetAnimationController()->GetAnimationFrameRect());
	//entity->GetVisualComponent()->Render((int)entity->GetPosX() - (int)camera->GetPosX(), (int)entity->GetPosY() - (int)camera->GetPosY(), sdlRenderer);
	entity->GetVisualComponent()->Render(round(entity->GetPosX()), round(entity->GetPosY()), sdlRenderer);

	if (debug == true)
	{
		SDL_Rect newRect{ round(entity->GetCollider()->GetPosX()), round(entity->GetCollider()->GetPosY()), entity->GetCollider()->GetWidth(), entity->GetCollider()->GetHeight() };
		SDL_RenderDrawRect(sdlRenderer, &newRect);
	}
}


void Renderer::Draw(std::vector<Entity*>* entityList)//, Camera* camera)
{
	SDL_RenderClear(sdlRenderer);
	for (unsigned i = 0; i < entityList->size(); ++i)
	{
		//Render((*entityList)[i]);
		Render(entityList->at(i));
	}
	SDL_RenderPresent(sdlRenderer);
}
void Renderer::SetRenderer(SDL_Renderer* renderer)
{
	sdlRenderer = renderer;
}
SDL_Renderer* Renderer::GetRenderer()
{
	return sdlRenderer;
}

bool Renderer::Initialize()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not be initialized. SDL error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		sdlWindow = SDL_CreateWindow("Platform Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (sdlWindow == NULL)
		{
			std::cout << "SDL Window could not be created. SDL error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//SDL_SetWindowFullscreen(sdlWindow, SDL_WINDOW_FULLSCREEN);
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
			if (sdlRenderer == NULL)
			{
				std::cout << "SDL Renderer could not be created. SDL error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags)) & imgFlags)
				{
					std::cout << "SDL Img could not be initialized. SDL Img error: " << IMG_GetError() << std::endl;
					success = false;
				}
			}
		}
	}
	return success;
}