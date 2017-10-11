#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();
	void LoadTexture(std::string path, SDL_Renderer* renderer);
	void FreeTexture();
	void Render(int posX, int posY, SDL_Rect* cutRect, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	SDL_Texture* texture;
	int width;
	int height;

};

