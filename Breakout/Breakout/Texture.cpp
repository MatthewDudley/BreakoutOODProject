#include "Texture.h"

Texture::Texture()
{
	texture = NULL;
	width = 0;
	height = 0;
}

Texture::~Texture()
{
	FreeTexture();
}

void Texture::LoadTexture(std::string path, SDL_Renderer* renderer)
{
	FreeTexture();

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image at path: " << path << " SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL)
		{
			std::cout << "Unable to create texture. SDL error: " << SDL_GetError() << std::endl;
		}
		else
		{
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
}

void Texture::FreeTexture()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}
void Texture::Render(int posX, int posY, SDL_Rect* cutRect, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	if (cutRect == NULL || cutRect == nullptr)
	{
		std::cout << "cutRect is null" << std::endl;
	}
	else if (renderer == NULL || renderer == nullptr)
	{
		std::cout << "renderer is null" << std::endl;
	}
	else
	{
		SDL_Rect rect{ posX - cutRect->w / 2, posY - cutRect->h / 2, cutRect->w, cutRect->h };
		//SDL_RenderCopyEx(renderer, texture, cutRect, &rect, 0.0, NULL, flip);
		SDL_RenderCopyEx(renderer, texture, cutRect, &rect, 0.0, NULL, flip);	
	}
}
