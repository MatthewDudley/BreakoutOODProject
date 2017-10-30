#include "Paddle.h"
#include "SingleImageController.h"
#include "PhysicsComponent.h"
#include "Collider.h"

Paddle::Paddle(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset) : Entity(x, y, collWidth, collHeight, collXOffset, collYOffset, "paddle")
{
	visualComponent = new SingleImageController();
	physicsComponent = new PhysicsComponent(this);
}


Paddle::~Paddle()
{

}

void Paddle::Update()//std::vector<Entity*> entityList)
{
	//update logic here
	physicsComponent->Update();
	if (GetPosX() < leftBounds)
	{
		SetPosX(leftBounds);
	}
	else if (GetPosX() + GetCollider()->GetWidth() > rightBounds)
	{
		SetPosX(rightBounds - GetCollider()->GetWidth());
	}
}

void Paddle::SetBounds(float leftBounds, float rightBounds)
{
	this->leftBounds = leftBounds;
	this->rightBounds = rightBounds;
}


SingleImageController* Paddle::GetSingleImageController()
{
	return (SingleImageController*)visualComponent;
}
