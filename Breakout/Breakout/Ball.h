#pragma once
#include "Entity.h"
#include <vector>
#include "Subject.h"
class SingleImageController;
class Collider;
class Ball : public Entity, public Subject
{
public:
	Ball(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset, float speedModifier, float speedUpAmount, float maxSpeed);
	~Ball();

	void Update(std::vector<Entity*> entityList);
	SingleImageController* GetSingleImageController();

private:
	Vector2* startingPosition;
	enum CollisionSide{NONE, TOP, RIGHT, BOTTOM, LEFT};
	bool CheckCollisions(Collider* other);
	CollisionSide HandleHorizontalCollisions(std::vector<Entity*> entityList);
	CollisionSide HandleVerticalCollisions(std::vector<Entity*> entityList);
	float collisionResolutionOffset = 0.001f;
	bool paddleHit = false;
	void IncrementSpeedModifier();
	float hitPosition = 0.0f;
	float speedModifier = 0;
	float startingSpeedModifier = 0;
	float speedUpAmount = 0;
	float maxSpeed = 0;
	void ResetBall();
};

