#pragma once
#include "Entity.h"

class SingleImageController;
class Paddle : public Entity
{
public:
	Paddle(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset);
	~Paddle();
	void SetBounds(float leftBounds, float rightBounds);

	void Update();
	SingleImageController* GetSingleImageController();
private:
	float leftBounds = 0;
	float rightBounds = 0;
};