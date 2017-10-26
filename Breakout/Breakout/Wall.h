#pragma once
#include "Entity.h"

class SingleImageController;
class Wall : public Entity
{
public:
	Wall(float x, float y, int collWidth, int collHeight);
	~Wall();
	SingleImageController* GetSingleImageController();
};
