#pragma once
#include "Entity.h"
#include "Subject.h"

class SingleImageController;
class Brick : public Entity, public Subject
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

