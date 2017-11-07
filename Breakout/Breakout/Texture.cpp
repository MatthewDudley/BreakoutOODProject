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

void Texture::LoadText(std::string message, SDL_Color textColor, TTF_Font* font, SDL_Renderer* renderer)
{
	FreeTexture();

	SDL_Surface* loadedSurface = TTF_RenderText_Solid(font, message.c_str(), textColor);
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load text surface. TTF Error: " << TTF_GetError() << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL)
		{
			std::cout << "Unable to create texture from text. SDL error: " << SDL_GetError() << std::endl;
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

int Texture::GetWidth()
{
	return width;
}
int Texture::GetHeight()
{
	return height;
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
		//If we want the position to be the middle, do this calculation
		//SDL_Rect rect{ posX - cutRect->w / 2, posY - cutRect->h / 2, cutRect->w, cutRect->h };

		//If we want the position to be the top left do this calcuation
		SDL_Rect rect{ posX, posY, cutRect->w, cutRect->h };

		//Not a memory leak? Memory is just slowly allocated but has an upper bounds
		SDL_RenderCopyEx(renderer, texture, cutRect, &rect, 0.0, NULL, flip);	
	}
}
