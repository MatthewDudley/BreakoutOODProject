#pragma once
#include "Entity.h"
#include <vector>
class SingleImageController;
class Collider;
class Ball : public Entity
{
public:
	Ball(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset);
	~Ball();


	//void SetVelocityY(float velocityY);

	void Update(std::vector<Entity*> entityList);
	SingleImageController* GetSingleImageController();

private:
	enum CollisionSide{NONE, TOP, RIGHT, BOTTOM, LEFT};
	bool CheckCollisions(Collider* other);
	CollisionSide HandleHorizontalCollisions(std::vector<Entity*> entityList);
	CollisionSide HandleVerticalCollisions(std::vector<Entity*> entityList);
	float collisionResolutionOffset = 0.001f;
	bool paddleHit = false;
	float hitPosition = 0.0f;
};

