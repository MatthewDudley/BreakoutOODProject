#pragma once
class Vector2;
class Entity;
class PhysicsComponent
{
public:
	PhysicsComponent(Entity* parentEntity);
	~PhysicsComponent();
	void SetVelocity(float x, float y);
	void SetVelocity(Vector2* velocity);
	void SetMaxSpeed(float maxSpeed);
	Vector2* GetVelocity();
	float GetMaxSpeed();
	void Update();
	void UpdateHorizontal();
	void UpdateVertical();
private:
	Vector2* velocity;
	Entity* parentEntity;
	float maxSpeed;
};

