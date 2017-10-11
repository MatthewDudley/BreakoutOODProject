#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
//#include "Entity.h"
//#include "Camera.h"
//#include <vector>
class Renderer
{
public:
	Renderer(int screenWidth, int screenHeight, bool debug);
	~Renderer();
	//void Render();//Entity* entity, Camera* camera);
	SDL_Renderer* GetRenderer();
	void SetRenderer(SDL_Renderer* renderer);
	void Draw();//std::vector<Entity*>* entityList, Camera* camera);
	bool Initialize();
private:
	SDL_Renderer* sdlRenderer;
	SDL_Window* sdlWindow;
	int screenWidth;
	int screenHeight;
	bool debug;
};

