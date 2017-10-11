#include "SingleImageController.h"
#include "Texture.h"

SingleImageController::SingleImageController()
{
	currentSpriteRect = nullptr;
	//Temporarily set a sprite rect: change when adding sprite sheets
	std::cout << "SingleImageController: Temporarily set sprite rect in constructor" << std::endl;
	SetCurrentSpriteRect(0, 0, 100, 100);
}


SingleImageController::~SingleImageController()
{
	delete currentSpriteRect;
	currentSpriteRect = nullptr;
}
void SingleImageController::SetCurrentSpriteRect(int posX, int posY, int width, int height)
{
	if (currentSpriteRect != nullptr)
	{
		delete currentSpriteRect;
		currentSpriteRect = nullptr;
	}
	currentSpriteRect = new SDL_Rect{ posX, posY, width, height };
}
void SingleImageController::Render(int entityX, int entityY, SDL_Renderer* renderer)
{
	texture->Render(entityX, entityY, currentSpriteRect, renderer);
}
