#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();
	void LoadTexture(std::string path, SDL_Renderer* renderer);
	void LoadText(std::string message, SDL_Color textColor, TTF_Font* font, SDL_Renderer* renderer);
	void FreeTexture();
	void Render(int posX, int posY, SDL_Rect* cutRect, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	int GetWidth();
	int GetHeight();
private:
	SDL_Texture* texture;
	int width;
	int height;

};

