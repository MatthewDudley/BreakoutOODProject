#pragma once
#include <SDL.h>
#include <iostream>
class Texture;
class VisualComponent;
class Vector2;
class PhysicsComponent;
class Collider;
//#include"Collider.h"
//#include "Vector2.h"
class Entity
{
public:
	Entity(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset);
	~Entity();

	void SetPosX(float x);
	void SetPosY(float y);
	//void SetColliderWidth(int width);
	//void SetColliderHeight(int height);

	float GetPosX();
	float GetPosY();
	//float GetCollXOffset();
	//float GetCollYOffset();
	Collider* GetCollider();
	VisualComponent* GetVisualComponent();
	PhysicsComponent* GetPhysicsComponent();

private:
	Vector2* position;
	//float collSizeOffset;

protected:
	Collider* col;
	VisualComponent* visualComponent = nullptr;
	PhysicsComponent* physicsComponent = nullptr;
	float collXOffset;
	float collYOffset;
};

