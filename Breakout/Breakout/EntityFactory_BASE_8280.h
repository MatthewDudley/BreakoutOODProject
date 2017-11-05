#pragma once
#include <iostream>
class Entity;
class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();
	enum class EntityType { Paddle, Ball, Brick };
	Entity* CreateEntity(EntityType entityType);
	static EntityFactory& GetInstance();

private:
	static EntityFactory instance;
};