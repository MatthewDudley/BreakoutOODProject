#include "Renderer.h"
#include <SDL_ttf.h>
#include "TextElement.h"
#include "Entity.h"
#include "VisualComponent.h"
#include "Collider.h"
#include "math.h"

Renderer::Renderer()
{
	//this->screenWidth = screenWidth;
	//this->screenHeight = screenHeight;
	//this->debug = debug;
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

Renderer& Renderer::GetInstance()
{
	//No need to check if the instance exists, C++ won't create another static instance
	//Also thread safe by default, C++ automatically locks on instance creation
	static Renderer instance;
	return instance;
}


void Renderer::Render(Entity* entity)//, Camera* camera)
{
	entity->GetVisualComponent()->Render(round(entity->GetPosX()), round(entity->GetPosY()), sdlRenderer);

	if (debug == true)
	{
		SDL_Rect newRect{ round(entity->GetCollider()->GetPosX()), round(entity->GetCollider()->GetPosY()), entity->GetCollider()->GetWidth(), entity->GetCollider()->GetHeight() };
		SDL_RenderDrawRect(sdlRenderer, &newRect);
	}
}


void Renderer::Draw(std::vector<Entity*>* entityList, std::vector<TextElement*>* textList)//, Camera* camera)
{
	SDL_RenderClear(sdlRenderer);
	for (unsigned i = 0; i < entityList->size(); ++i)
	{
		//Render((*entityList)[i]);
		Render(entityList->at(i));
	}

	for (unsigned i = 0; i < textList->size(); ++i)
	{
		textList->at(i)->Render();
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

bool Renderer::Initialize(int screenWidth, int screenHeight, bool debug)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->debug = debug;
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
				//SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF); old just white one
				SDL_SetRenderDrawColor(sdlRenderer, 0xB9, 0xD9, 0xEE, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags)) & imgFlags)
				{
					std::cout << "SDL Img could not be initialized. SDL Img error: " << IMG_GetError() << std::endl;
					success = false;
				}
				if (TTF_Init() == -1)
				{
					std::cout << "SDL ttf could not initialize. SDL ttf Error: " << TTF_GetError() << std::endl;
					success = false;
				}
			}
		}
	}
	return success;
}

int Renderer::GetScreenWidth()
{
	return screenWidth;
}
int Renderer::GetScreenHeight()
{
	return screenHeight;
}