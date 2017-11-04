#pragma once
#include <iostream>
class Entity;
class EntityFactory
{
public:
	enum class EntityType { Paddle, Ball, Brick };
	Entity* CreateEntity(EntityType entityType);
	static EntityFactory& GetInstance();

private:
	static EntityFactory instance;
	EntityFactory() {}
	~EntityFactory() {}
};

