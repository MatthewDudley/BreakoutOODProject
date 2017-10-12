#pragma once
#include "Entity.h"
#include <vector>

class SingleImageController;
class Paddle : public Entity
{
public:
	Paddle(float x, float y);// , int width, int height, float collXOffset, float collYOffset);
	~Paddle();

	//void AddVelocity(float x, float y);
	//void SetVelocityX(float velocityX);
	//void SetVelocityY(float velocityY);

	void Update(std::vector<Entity*> entityList);
	SingleImageController* GetSingleImageController();

	//void GetInput(PlayerActions action, InputType type);

	//PlayerState::Direction MoveHorizontal(std::vector<Entity*> entityList);


private:
	Vector2* velocity;
	float speed;
	//bool CheckCollisions(Collider* other);



};