#include "Paddle.h"
#include "SingleImageController.h"
#include "PhysicsComponent.h"

Paddle::Paddle(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset) : Entity(x, y, collWidth, collHeight, collXOffset, collYOffset)
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
}

/*
bool Player::CheckCollisions(Collider* other)
{
	if ((GetCollider()->GetPosX() + GetCollider()->GetWidth() < other->GetPosX()) || (GetCollider()->GetPosX() > (other->GetPosX() + other->GetWidth())) ||
		(GetCollider()->GetPosY() + GetCollider()->GetHeight() < other->GetPosY()) || (GetCollider()->GetPosY() > (other->GetPosY() + other->GetHeight())))
	{
		return false;
	}
	return true;
}
*/

SingleImageController* Paddle::GetSingleImageController()
{
	return (SingleImageController*)visualComponent;
}
