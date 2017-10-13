#pragma once
class Vector2;
class Entity;
class PhysicsComponent
{
public:
	PhysicsComponent(Entity* parentEntity, float maxSpeed);
	~PhysicsComponent();
	void SetVelocity(float x, float y);
	void SetVelocity(Vector2* velocity);
	Vector2* GetVelocity();
	void Update();
private:
	Vector2* velocity;
	Entity* parentEntity;
	float maxSpeed;
};

