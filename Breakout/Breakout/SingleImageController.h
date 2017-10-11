#pragma once
#include <SDL.h>
#include "VisualComponent.h"
class SingleImageController : public VisualComponent
{
public:
	SingleImageController();
	~SingleImageController();
	void Render(int entityX, int entityY, SDL_Renderer* renderer);
	void SetCurrentSpriteRect(int posX, int posY, int width, int height);
private:
	SDL_Rect* currentSpriteRect;
};

