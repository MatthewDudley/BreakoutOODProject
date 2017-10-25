#pragma once
#include "Entity.h"

class SingleImageController;
class Paddle : public Entity
{
public:
	Paddle(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset);
	~Paddle();

	//void AddVelocity(float x, float y);
	//void SetVelocityX(float velocityX);
	//void SetVelocityY(float velocityY);

	void Update();//std::vector<Entity*> entityList);
	SingleImageController* GetSingleImageController();

};