#pragma once
#include "Entity.h"

class SingleImageController;
class Brick : public Entity
{
public:
	Brick(float x, float y, int collWidth, int collHeight);
	~Brick();
	void Destroy();
	bool IsDestroyed();
	SingleImageController* GetSingleImageController();
private:
	bool destroyed;
};

