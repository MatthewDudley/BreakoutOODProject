#include "PhysicsComponent.h"
#include "Vector2.h"
#include "Entity.h"
#include "Time.h"

PhysicsComponent::PhysicsComponent(Entity* parentEntity)
{
	velocity = new Vector2(0.0f, 0.0f);
	this->parentEntity = parentEntity;
}

PhysicsComponent::~PhysicsComponent()
{
	delete velocity;
}

void PhysicsComponent::SetMaxSpeed(float maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void PhysicsComponent::Update()
{
	//multiply by delta time
	parentEntity->SetPosX(parentEntity->GetPosX() + (velocity->GetX() * Time::GetDeltaTime()));
	parentEntity->SetPosY(parentEntity->GetPosY() + (velocity->GetY() * Time::GetDeltaTime()));
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