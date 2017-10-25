#include "Collider.h"



Collider::Collider(float x, float y, int width, int height)
{
	rect = new SDL_Rect{ (int)x, (int)y, width, height };
	posX = x;
	posY = y;
	this->width = width;
	this->height = height;
}
Collider::~Collider()
{
	delete rect;
	rect = nullptr;
}

void Collider::SetPosX(float x)
{
	posX = x;
	ResetRect();
}
void Collider::SetPosY(float y)
{
	posY = y;
	ResetRect();
}
void Collider::SetWidth(int width)
{
	this->width = width;
	ResetRect();
}
void Collider::SetHeight(int height)
{
	this->height = height;
	ResetRect();
}

void Collider::ResetRect()
{
	delete rect;
	rect = new SDL_Rect{ (int)posX, (int)posY, width, height };
}

float Collider::GetPosX()
{
	return posX;
}
float Collider::GetPosY()
{
	return posY;
}
int Collider::GetWidth()
{
	return width;
}
int Collider::GetHeight()
{
	return height;
}
SDL_Rect* Collider::GetRect()
{
	return rect;
}