#pragma once
#include <SDL.h>
class Texture;
class VisualComponent
{
public:
	VisualComponent();
	virtual ~VisualComponent();
	virtual void Render(int entityX, int entityY, SDL_Renderer* renderer) = 0;
	void SetTexture(Texture* texture);
protected:
	Texture* texture;
};

