#pragma once
#include <SDL.h>
#include <iostream>
class Texture;
class VisualComponent;
//#include"Collider.h"
//#include "Vector2.h"
class Entity
{
public:
	Entity(float x, float y);//, int collWidth, int collHeight, float collXOffset, float collYOffset, bool isTrigger);
	~Entity();

	void SetPosX(float x);
	void SetPosY(float y);
	//void SetColliderWidth(int width);
	//void SetColliderHeight(int height);

	float GetPosX();
	float GetPosY();
	//float GetCollXOffset();
	//float GetCollYOffset();
	//Collider* GetCollider();
	VisualComponent* GetVisualComponent();

private:
	//Vector2* position;
	//Collider* col;
	float positionX;
	float positionY;
	//float collXOffset;
	//float collYOffset;
	//float collSizeOffset;

protected:
	VisualComponent* visualComponent;
};

