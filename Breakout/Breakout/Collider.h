#pragma once
#include <SDL.h>
#include <stdio.h>

class Collider
{
public:
	Collider(float x, float y, int width, int height);
	~Collider();

	float GetPosX();
	float GetPosY();
	int GetWidth();
	int GetHeight();
	SDL_Rect* GetRect();
	void SetPosX(float x);
	void SetPosY(float y);
	void SetWidth(int width);
	void SetHeight(int height);

private:
	float posX;
	float posY;
	int width;
	int height;
	SDL_Rect* rect;
	void ResetRect();
};

