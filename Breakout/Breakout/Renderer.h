#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
class Entity;
class TextElement;
//#include "Entity.h"
//#include "Camera.h"
//#include <vector>
class Renderer
{
public:
	static Renderer& GetInstance();
	~Renderer();
	void Render(Entity* entity);// , Camera* camera);
	SDL_Renderer* GetRenderer();
	void SetRenderer(SDL_Renderer* renderer);
	void Draw(std::vector<Entity*>* entityList, std::vector<TextElement*>* textList);//, Camera* camera);
	bool Initialize(int screenWidth, int screenHeight, bool debug);
	int GetScreenWidth();
	int GetScreenHeight();
private:
	Renderer();
	static Renderer instance;
	SDL_Renderer* sdlRenderer;
	SDL_Window* sdlWindow;
	int screenWidth;
	int screenHeight;
	bool debug;
};

