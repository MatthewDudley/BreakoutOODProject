#include "Ball.h"
#include "SingleImageController.h"
#include "Vector2.h"
#include "PhysicsComponent.h"
#include "Collider.h"

Ball::Ball(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset) : Entity(x, y, collWidth, collHeight, collXOffset, collYOffset, "ball")
{
	visualComponent = new SingleImageController();
	physicsComponent = new PhysicsComponent(this);
}


Ball::~Ball()
{

}

void Ball::Update(std::vector<Entity*> entityList)
{
	//update logic here
	physicsComponent->UpdateHorizontal();
	CollisionSide horizontalSide = HandleHorizontalCollisions(entityList);
	physicsComponent->UpdateVertical();
	CollisionSide verticalSide = HandleVerticalCollisions(entityList);
	if (horizontalSide != CollisionSide::NONE || verticalSide != CollisionSide::NONE)
	{
		//If there was a collision
		if (verticalSide == CollisionSide::NONE)
		{
			if (horizontalSide == CollisionSide::LEFT)
			{
				physicsComponent->SetVelocity(&Vector2::GetReflectionAngle(physicsComponent->GetVelocity(), &Vector2(1, 0)));
			}
			else
			{
				physicsComponent->SetVelocity(&Vector2::GetReflectionAngle(physicsComponent->GetVelocity(), &Vector2(-1, 0)));

			}
		}
		else if (horizontalSide == CollisionSide::NONE)
		{
			//if it was a vertical collision
			if (verticalSide == CollisionSide::BOTTOM)
			{
				physicsComponent->SetVelocity(&Vector2::GetReflectionAngle(physicsComponent->GetVelocity(), &Vector2(0, 1)));
			}
			else
			{
				physicsComponent->SetVelocity(&Vector2::GetReflectionAngle(physicsComponent->GetVelocity(), &Vector2(0, -1)));
			}
		}
		else
		{
			//if it was both a vertical and horizontal collision (corner)
			//Never actually gets called due to collision offsets. look into?
			physicsComponent->SetVelocity(-physicsComponent->GetVelocity()->GetX(), -physicsComponent->GetVelocity()->GetY());
		}
	}
}

bool Ball::CheckCollisions(Collider* other)
{
	if ((GetCollider()->GetPosX() + GetCollider()->GetWidth() < other->GetPosX()) || 
		(GetCollider()->GetPosX() > (other->GetPosX() + other->GetWidth())) ||
		(GetCollider()->GetPosY() + GetCollider()->GetHeight() < other->GetPosY()) || 
		(GetCollider()->GetPosY() > (other->GetPosY() + other->GetHeight())))
	{
		return false;
	}
	return true;
}

Ball::CollisionSide Ball::HandleHorizontalCollisions(std::vector<Entity*> entityList)
{
	CollisionSide side = CollisionSide::NONE;
	for (unsigned i = 0; i < entityList.size(); ++i)
	{
		if (this != entityList[i])
		{
			if (CheckCollisions(entityList[i]->GetCollider()))
			{
				//If there was a collision
				if (col->GetPosX() > entityList[i]->GetCollider()->GetPosX())
				{
					SetPosX(entityList[i]->GetCollider()->GetPosX() + entityList[i]->GetCollider()->GetWidth() - collXOffset + collisionResolutionOffset); //+  collisionResolutionOffset);
					side = CollisionSide::LEFT;
				}
				else
				{
					SetPosX(entityList[i]->GetCollider()->GetPosX() - col->GetWidth() - collXOffset - collisionResolutionOffset);//- collisionResolutionOffset - this->GetCollXOffset());
					side = CollisionSide::RIGHT;
				}
				//end if there was a collision
			}
		}
	}
	return side;
}

Ball::CollisionSide Ball::HandleVerticalCollisions(std::vector<Entity*> entityList)
{
	CollisionSide side = CollisionSide::NONE;
	for (unsigned i = 0; i < entityList.size(); ++i)
	{
		if (this != entityList[i])
		{
			if (CheckCollisions(entityList[i]->GetCollider()))
			{
				if (col->GetPosY() < (entityList[i]->GetCollider()->GetPosY()))
				{
					SetPosY(entityList[i]->GetCollider()->GetPosY() - col->GetHeight() - collYOffset - collisionResolutionOffset);// - collisionResolutionOffset - this->GetCollYOffset());
					side = CollisionSide::BOTTOM;
				}
				else
				{
					SetPosY(entityList[i]->GetCollider()->GetPosY() + entityList[i]->GetCollider()->GetHeight() - collYOffset + collisionResolutionOffset);//+ collisionResolutionOffset - this->GetCollYOffset());
					side = CollisionSide::TOP;
				}
			}
		}
	}
	return side;
}


SingleImageController* Ball::GetSingleImageController()
{
	return (SingleImageController*)visualComponent;
}
