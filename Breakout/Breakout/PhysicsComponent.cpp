#include "PhysicsComponent.h"
#include "Vector2.h"
#include "Entity.h"

PhysicsComponent::PhysicsComponent(Entity* parentEntity, float maxSpeed)
{
	this->maxSpeed = maxSpeed;
	velocity = new Vector2(0.0f, 0.0f);
	this->parentEntity = parentEntity;
}

PhysicsComponent::~PhysicsComponent()
{
	delete velocity;
}

void PhysicsComponent::Update()
{
	//multiply by delta time
	parentEntity->SetPosX(parentEntity->GetPosX() + velocity->GetX());
	parentEntity->SetPosY(parentEntity->GetPosY() + velocity->GetY());
}

void PhysicsComponent::SetVelocity(float x, float y)
{
	velocity->SetX(x);
	velocity->SetY(y);
}

void PhysicsComponent::SetVelocity(Vector2* velocity)
{
	this->velocity->SetX(velocity->GetX());
	this->velocity->SetY(velocity->GetY());
}

Vector2* PhysicsComponent::GetVelocity()
{
	return velocity;
}